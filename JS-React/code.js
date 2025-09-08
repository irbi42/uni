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
                err += 'Поле [' + field + '] должно быть [' + expectedType + '] ';
            };
        };
        if(isValid){
            return "valid: true"
        }
        return "valid: false, errors: " + err;
    };
}


const rules = {name: 'string', age: 'number', isAdmin: 'boolean', hobbies: 'array'};
const validate = createValidator(rules);

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
console.log("user: " + validate(user));

console.log("admin: " + validate(admin));