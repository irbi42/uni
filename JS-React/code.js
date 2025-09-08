console.log("Hello!");

function analyzeUser(user) {
    let isadmin = "Нет";
    if (user.isAdmin) {
        isadmin = "Да";
    };
    var result = "Пользователь: " + user.name + ", возраст: " + user.age + ". Администратор: "+ isadmin + ". Увлечения: " + user.hobbies + ".";
    return result;
}

const user = {
    name: "Tom",
    age: 12,
    isAdmin: false,
    hobbies: ["Видеоигры", "Рисование"]
};

const admin = {
    name: "Bob",
    age: 22,
    isAdmin: true,
    hobbies: ["Видеоигры", "Программирование", "вязание"]
};
console.log(analyzeUser(user));
console.log(analyzeUser(admin));