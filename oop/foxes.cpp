#include <iostream>
#include <fstream>
#include <list>
#include <vector>

int fieldRows;
int fieldCols;

using namespace std;

class animal {
    protected:
    int id;
    int parentId;
    int x;
    int y;
    int stability;
    int direction;

    int age;
    const int leap = 1;

    int getCoreStability()
    {
        return stability;
    }

    public:
    animal(int x, int y, int s, int d) : x(x), y(y), stability(s), direction(d), age(0){}
    animal(animal *parent) : x(parent->getX()), y(parent->getY()), age(0)
    {
        stability = parent->getCoreStability();
        direction = parent->getDirection();
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    int getDirection(){
        return direction;
    }

    void changeDirection() {
        direction = (direction + 1) % 4;
    }

    int getStability ()
    {
        return (age + 1) % stability;
    }

    int getAge()
    {
        return age;
    }

    void ageUp() {
        age++;
    }

    

};

class rabbit : public animal
{
    protected:
    const int leap = 1;
    
    public:
    rabbit(int x, int y, int s, int d) : animal(x, y, s, d) {}
    rabbit(rabbit *parent) : animal(parent) {}

    void move(){
        switch (direction) {
            case 0:
                y -= leap;
            break;
            case 1:
                x += leap;
            break;
            case 2:
                y += leap;
            break;
            case 3:
                x-= leap;
            break;
        }
        x = (x + fieldCols) % fieldCols;
        y = (y + fieldRows) % fieldRows;
    }
};

class fox : public animal
{
    protected:
    const int leap = 2;
    int hasEaten = 0;

    public:
    fox(int x, int y, int s, int d) : animal(x, y, s, d) {}
    fox(fox *parent) : animal(parent) {}

    void move(){
        switch (direction) {
            case 0:
                y -= leap;
            break;
            case 1:
                x += leap;
            break;
            case 2:
                y += leap;
            break;
            case 3:
                x-= leap;
            break;
        }
        x = (x + fieldCols) % fieldCols;
        y = (y + fieldRows) % fieldRows;
    }

    void eat()
    {
        hasEaten++;
    }

    void hungry()
    {
        hasEaten = 0;
    }

    int eaten()
    {
        return hasEaten;
    }

};

class model
{
    private:
    int steps;
    int currentStep;
    bool verbose;
    string outfile;
    int foxesCount;
    int rabbitsCount;
    list<fox> massF;
    list<rabbit> massR;
    vector<vector<int>> field;

    private:

    void fillField()
    {

        for(int i = 0; i < fieldRows; i++)
        {
            for (int j = 0; j < fieldCols; j++)
            {
                field[i][j] = 0;
            }
        }

        for (auto it : massR)
        {
            field[it.getY()][it.getX()] += 1;
        }

        for (auto it : massF)
        {
            if(field[it.getY()][it.getX()] > 0) 
            {
                field[it.getY()][it.getX()] = 0;
            }
            field[it.getY()][it.getX()] -= 1;
        }

    }
    
    bool validate(int x, int y, int d)
    {
        if (x < 0 || x >= fieldCols)
        {
            return false;
        }
        if (y < 0 || y >= fieldRows)
        {
            return false;
        }
        if (d < 0 || d > 3)
        {
            return false;
        }
        return true;
    }

    void move()
    {
        for(auto &it : massR)
        {
            it.move();
            if(it.getStability() == 0)
            {
                it.changeDirection();
            }
        }

        for(auto &it : massF)
        {
            it.move();
            if(it.getStability() == 0)
            {
                it.changeDirection();
            }
        }
    }

    void eat()
    {
        for(auto &it : massF)
        {
            massR.remove_if([&it](auto r){
                bool eaten = r.getX() == it.getX() && r.getY() == it.getY();
                if(eaten)
                {
                    it.eat();
                }
                return eaten;
            });
        }
    }

    void age()
    {
        for(auto &it : massF)
        {
            it.ageUp();
        }
        for(auto &it : massR)
        {
            it.ageUp();
        }
    }

    void breed() 
    {
        for (auto &it : massR)
        {
            if(it.getAge() == 5 || it.getAge() == 10)
            {
                rabbit r(&it);
                massR.push_back(r);
            }
        }

        for (auto &it : massF)
        {
            if(it.eaten() >= 2)
            {
                fox f(&it);
                massF.push_back(f);
                it.hungry();
            }
        }

    }

    void die()
    {
        massR.remove_if([](auto x) {
            return x.getAge() >= 10;
        });

        massF.remove_if([](auto x) {
            return x.getAge() >= 15;
        });

    }

    void writeResult()
    {
        ofstream out(outfile);

        if (!out.is_open())
        {
            cerr << "Ошибка: не удалось открыть файл " << outfile << " для записи" << std::endl;
        }

        for(int i = 0; i < fieldRows; i++)
        {
            for(int j = 0; j < fieldCols; j++)
            {
                if (field[i][j] == 0)
                {
                    out << " *" << ' ';
                } else {
                    if (field[i][j] > 0) cout << ' ';
                    out << field[i][j] << ' ';
                }
            }
            out << endl;
        }
        out.close();
        cout << "Сохранено в файл: " << outfile << endl;
    }

    public:
    model(const string filename, const string out, bool v) : currentStep(1), verbose(v), outfile(out)
    {
        ifstream in(filename);
        if(!in.is_open())
        {
            cerr << "cannot open file" << std::endl;
        }
        in >> fieldCols >> fieldRows >> steps;
        in.ignore(10000, '\n');
        in >> rabbitsCount >> foxesCount;
        in.ignore(10000, '\n');

        field = vector<vector<int>>(fieldRows, vector<int>(fieldCols, 0));

        for (int i = 0; i < rabbitsCount; i++)
        {
            int x, y, d, s;
            in >> x >> y >> d >> s;
            in.ignore(10000, '\n');
            if (!validate(x, y, d))
            {
                in.close();
                throw ios_base::failure("Некорректные данные в строке описывающей кролика"); 
            }
            rabbit tmp(x, y, s, d);
            massR.push_back(tmp);
        }

        for (int i = 0; i < foxesCount; i++)
        {
            int x, y, d, s;
            in >> x >> y >> d >> s;
            in.ignore(10000, '\n');
            if (!validate(x, y, d))
            {
                in.close();
                throw ios_base::failure("Некорректные данные в строке описывающей лису"); 
            }
            fox tmp(x, y, s, d);
            massF.push_back(tmp);
        }

        fillField();

        in.close();
    }

    ~model(){}

    

    void print() {

        for(int i = 0; i < fieldRows; i++)
        {
            for(int j = 0; j < fieldCols; j++)
            {
                if (field[i][j] == 0)
                {
                    cout << " *" << ' ';
                } else {
                    if (field[i][j] > 0) cout << ' ';
                    cout << field[i][j] << ' ';
                }
            }
            cout << endl;
        }

        cout << "Rabbits" << endl;
        for (auto it : massR)
        {
            cout << "(" << it.getX() << " " << it.getY() << " A" << it.getAge() << ")";
        }
        cout << endl;

        cout << "Foxes" << endl;
        for (auto it : massF)
        {
            cout << "(" << it.getX() << " " << it.getY() << " A" << it.getAge() << " ";
            char c = it.eaten() > 0 ? 'F' : 'H';
            cout << c << ")";
        }
        cout << endl;
    }

    void step()
    {
        if (verbose) cout << "moving...";
        move();
        if (verbose) cout << "eating...";
        eat();
        if (verbose) cout << "aging...";
        age();
        if (verbose) cout << "breeding...";
        breed();
        if (verbose) cout << "grim reaper working...";
        die();
        if (verbose) cout << "cycle complete!" << endl;
        fillField();
        
    }

    void run()
    {
        while(currentStep <= steps)
        {
            if (verbose) cout << "Ход " << currentStep << endl;
            step();
            if (verbose) print();
            if (verbose) cout << endl;
            currentStep++;
        }

        if (verbose) cout << "simulation complete! writing in " << outfile << endl;
        writeResult();
    }
};

int main(int argc, char*argv[])
{

    if (argc < 3) {
        std::cerr << "Ошибка: не указан обязательный аргумент!" << std::endl;
        std::cerr << "Использование: " << argv[0] << " <имя файла ввода> <имя файла вывода> [-v(вывод в консоль)]" << std::endl;
        return 1;
    }
    string input = argv[1];
    string output = argv[2];
    bool verbose = false;
    string arg = argv[3];
    if (argc > 3)
    {
        if (argc > 4)
        {
            std::cerr << "Ошибка: слишком много аргументов!" << std::endl;
            std::cerr << "Использование: " << argv[0] << " <имя файла> [-v(вывод в консоль)]" << std::endl;
            return 1;
        }

        if (arg == "-v")
        {
            verbose = true;
        } else {
            std::cerr << "Ошибка: неизвестный аргумент!" << std::endl;
            std::cerr << "Использование: " << argv[0] << " <имя файла> [-v(вывод в консоль)]" << std::endl;
            return 1;
        }
    }
    try
    {
        model play(input, output, verbose);
        if (verbose) {
            cout << "Начальное поле: " << endl; 
            play.print();
        }
        play.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}
