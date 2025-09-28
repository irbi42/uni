console.log("Hello!");

function analyzeUser(user) {
    let isadmin = "Нет";
    if (user.isAdmin) {
        isadmin = "Да";
    };
    var result = "Пользователь: " + user.name + ", возраст: " + user.age + ". Администратор: "+ isadmin + ". Увлечения: " + user.hobbies + ".";
    return result;
}

function createValidator (rules) {
    return function validate(data) {
        let err = "";
        let isValid = true;
        for (const [field, expectedType] of Object.entries(rules)) {
            const val = data[field];
            let actualType;

            if (Array.isArray(val)) {
                actualType = 'array';
            } else {
                actualType = typeof(val);
            };

            if (actualType != expectedType) {
                isValid = false;
                err += `Поле [${field}] должно быть [${expectedType}]; `;
            };
        };
        if(isValid){
            return "valid: true"
        }
        return "valid: false, errors: " + err;
    };
}

function processUserData (userJson) {
    const {name, birthDate, isPremium, skills} = JSON.parse(userJson);
//Проверка типов данных
    if (typeof(name) != 'string') {
        throw new Error("Поле name не строка");
    } else if (name.length < 2) {
        throw new Error("Имя должно быть минимум 2 символа");
    };

    if (typeof(birthDate) != 'string') {
        throw new Error("Поле birthDate не строка");
    } else if (birthDate[4] != '-' || birthDate[7] != '-' || birthDate.length != 10) {
        throw new Error("Поле birthDate не соответствует формату YYYY-MM-DD");
    }

    if (typeof(isPremium) != 'boolean') {
        throw new Error("Поле isPremium не boolean");
    }

    if (!Array.isArray(skills) && skills != null) {
        throw new Error("Неверный формат поля skills");
    }
//Преобразование даты рождения в возраст
    let now = new Date;
    let bDate = parseInt(birthDate);
    let age = now.getFullYear() - bDate;
//Добавляем поле hasSkills
    let hasSkills = (skills == null || skills.length == 0) ? false : true;

    return {name, age, isPremium, skills, hasSkills};
}

function filterAndSortTasks (tasksJson) {
    const tasks = JSON.parse(tasksJson);

    let unfinishedTasks = tasks.filter((task) => {
        return task.completed == false;
    });

    now = new Date();
    unfinishedTasks.sort((a, b) => {
        let timeLeftA = Date.parse(a.dueDate) - now; 
        let timeLeftB = Date.parse(b.dueDate) - now; 
        if (timeLeftA == timeLeftB) {
            return (a.priority > b.priority) ? 1 : -1;
        } else if (timeLeftA > timeLeftB) {
            return 1;
        } else return -1;
    });

    return unfinishedTasks;
}

function validateUserData(data) {
    let isValid;
    for (const [field, value] of Object.entries(data)) {
        let actualType = typeof(value);

        if (actualType == 'object') {
            validateUserData(value);
        } else if (field == 'id') {
            isValid = (actualType == 'number') ? true : false;
        } else {
            isValid = (actualType == 'string') ? true : false;
        }
        if (!isValid) {
            return isValid;
        }
    }
    return isValid
}

async function fetchAndProcessUsers() {
    // получить пользователей ий API
    let processedData = fetch ('https://jsonplaceholder.typicode.com/users')
    .then ((response) => {
        return response.json()
    })
    .then ((users) => {
        let isValid
        let validUsers = []
        for (let user of users) {
            isValid = validateUserData(user)
            let generatedDoB = new Date(Math.floor(Math.random() * 1577880000000))
            let now = new Date()
            user.age = now.getFullYear() - generatedDoB.getFullYear()
            if (isValid && user.website.endsWith('.com')) {
                validUsers.push(user)
            }

        }
        validUsers.sort((a, b) => {
            return (a.age > b.age ? -1 : 1)
        })
        return(validUsers)
    })

    return processedData
}

class ApiClient {
    constructor (url, ttl) {
        this.url = url
        this.ttl = ttl
        this.cache = new Map()
    }

    async get (endpoint) {
        const url = this.url + endpoint;
        const cached = this.cache.get(url);
        const now = Date.now();

        if (cached && (now - cached.timestamp) <= this.ttl) {
            return cached.data;
        }

        const controller = new AbortController();
        const timeoutId = setTimeout(() => controller.abort(), 5000);

        try {
            const response = await fetch(url, { signal: controller.signal });

            clearTimeout(timeoutId);

            if (response.status !== 200) {
            throw new Error(`HTTP error! status: ${response.status}`);
        }

        const data = await response.json();
        this.cache.set(url, { data, timestamp: now });

        return data;
        } catch (err) {
            if (err.name === 'AbortError') {
                throw new Error('Request aborted due to timeout');
            } else if (err.message === 'Failed to fetch') {
                throw new Error('Network error: Failed to fetch');
            }
            throw err;
        }
    }
}


// Задание 1
const user = {
    name: "Tom",
    age: 12,
    isAdmin: false,
    hobbies: ["Видеоигры", "Рисование"]
};
console.log(analyzeUser(user));

const admin = {
    name: 1,
    age: "22",
    isAdmin: true,
    hobbies: ["Видеоигры", "Программирование", "вязание"]
};

const rules = {name: 'string', age: 'number', isAdmin: 'boolean', hobbies: 'array'};
const validate = createValidator(rules);

console.log("user: " + validate(user));

console.log("admin: " + validate(admin));

// Задание 2
const userJson = `{
 "name": "Alice",
 "birthDate": "1995-05-12",
 "isPremium": true,
 "skills": ["JavaScript", "React"]
}`;

console.log(processUserData(userJson));

const tasksJson = `[
 {"id": 1, "title": "Купить продукты", "dueDate": "2025-10-25", "completed":
false, "priority": 1},
{"id": 2, "title": "Купить порошок", "dueDate": "2025-10-24", "completed":
false, "priority": 2},
{"id": 3, "title": "погулять с собакой", "dueDate": "2025-10-24", "completed":
false, "priority": 3},
{"id": 4, "title": "приготовить поесть", "dueDate": "2025-10-24", "completed":
false, "priority": 1},
{"id": 5, "title": "Написать код", "dueDate": "2025-10-25", "completed":
false, "priority": 2},
 {"id": 6, "title": "Сделать ДЗ", "dueDate": "2025-10-20", "completed": false,
"priority": 1},
 {"id": 7, "title": "Позвонить маме", "dueDate": "2025-10-22", "completed": true,
"priority": 3}
]`;
console.log(filterAndSortTasks(tasksJson));

//Задание 3

(async () => {
 const users = await fetchAndProcessUsers();
 console.log(users);
})();


const api = new ApiClient("https://jsonplaceholder.typicode.com", 10000); 
(async () => {
 try {
 const post = await api.get("/posts/1"); // Запрашиваем и кэшируем
 console.log(post);
 setTimeout(async () => {
 const cachedPost = await api.get("/posts/1"); // Берётся из кэша
 console.log(cachedPost);
 }, 5000);
 setTimeout(async () => {
 const freshPost = await api.get("/posts/1"); // Новый запрос (TTL истёк)
 console.log(freshPost);
 }, 11000);
 } catch (error) {
 console.error("Ошибка:", error.message);
 }
})();