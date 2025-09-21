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

