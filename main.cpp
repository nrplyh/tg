#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;


class User  
{ 
protected:                
    string userName;          // имя пользователя 
    string password;          // пользователь 

public: 
    User(){} // Пользователь без параметров 

public: 

    string getUserName(){return userName;} // Геттер для name 
    void setUserName(string userName1) {userName = userName1;} // Сеттер для name 

    string getPassword(){return password;} // Геттер для password 
    void setPassword(string password1) {password = password1;} // Сеттер для password 

    // Метод для отображения информации о пользователе 
    void displayUserInfo() 
    { 
        cout << "Name: " << userName << endl; 
        cout << "Password: " << password << endl; 
    } 
}; 

// Класс Client
class Client : public User { // Изменено на public чтобы методы User были доступны
    string email;
    string address;
    string phoneNumber;

    public:
    // Конструктор по умолчанию
    Client(){}

    // Конструктор с вызовом меню
    Client(string userName, string password) 
    {
        setUserName(userName);
        setPassword(password);
    }
 public:   
    string getEmail() //геттер для email 
    {return email;} 
    void setEmail(string email1){email = email1;} // Сеттер для email 

    string getAddress() //геттер для адреса 
    {return address;} 
    void setAddress(string address1){address = address1;} // Сеттер для адреса 

    string getPhoneNumber() //геттер для номера телефона 
    {return phoneNumber;} 
    void setPhoneNumber(string phoneNumber1){phoneNumber = phoneNumber1;} // Сеттер для номера телефона    

    // Метод для записи клиента в файл
    void saveToFile() {
        ofstream file("clients.txt", ios::app); // Открываем файл для добавления данных
        if (file.is_open()) {
            file << "Name: " << getUserName() << endl;
            file << "Password: " << getPassword() << endl;
            file << "Email: " << email << endl;
            file << "Address: " << address << endl;
            file << "-----------------------------" << endl;
            file.close();
            cout << "Данные клиента сохранены в файл clients.txt" << endl;
        } else {
            cout << "Ошибка открытия файла!" << endl;
        }
    }
};

class Cargo : public User { // Изменено на public чтобы методы User были доступны
    string phoneNumber;

    public:
    // Конструктор по умолчанию
    Cargo(){}

    // Конструктор с вызовом меню
    Cargo(string userName, string Password) 
    {
        setUserName(userName);
        setPassword(Password);
    }
 public:

    string getPhoneNumber() //геттер для номера телефона 
    {return phoneNumber;} 
    void setPhoneNumber(string phoneNumber1){phoneNumber = phoneNumber1;} // Сеттер для номера телефона    

    // Метод для записи кладовщика в файл
    void saveToFileCargo() {
        ofstream file("cargo.txt", ios::app); // Открываем файл для добавления данных
        if (file.is_open()) {
            file << "Name: " << getUserName() << endl;
            file << "Password: " << getPassword() << endl;
            file << "phoneNumber: " << getPhoneNumber() << endl;
            file << "-----------------------------" << endl;
            file.close();
            cout << "Данные кладовщика сохранены в файл cargo.txt" << endl;
        } else {
            cout << "Ошибка открытия файла!" << endl;
        }
    }
};

class Admin : public User { // Изменено на public чтобы методы User были доступны
    string phoneNumber;

    public:
    // Конструктор по умолчанию
    Admin(){}

    // Конструктор с вызовом меню
    Admin(string userName, string password) 
    {
        setUserName(userName);
        setPassword(password);
    }
 public:

    string getPhoneNumber() //геттер для номера телефона 
    {return phoneNumber;} 
    void setPhoneNumber(string phoneNumber1){phoneNumber = phoneNumber1;} // Сеттер для номера телефона    

    // Метод для записи Админа в файл
    void saveToFileAdmin() {
        ofstream file("admin.txt", ios::app); // Открываем файл для добавления данных
        if (file.is_open()) {
            file << "Name: " << getUserName() << endl;
            file << "Password: " << getPassword() << endl;
            file << "phoneNumber: " << getPhoneNumber() << endl;
            file << "-----------------------------" << endl;
            file.close();
            cout << "Данные админа сохранены в файл cargo.txt" << endl;
        } else {
            cout << "Ошибка открытия файла!" << endl;
        }
    }
};


void EnterUser(User &MyUSer);

class Product { 
    private: 
        int id;                // Идентификатор товара 
        string name;      // Название товара 
        double price;          // Цена товара 
        double selfprice;      // Себестоимость товара 
        int amount;
        int sold;

    public: 
        // Пустой конструктор с установкой значений по умолчанию 
        Product() : id(0), name("NULL"), price(0.0), selfprice(0.0), amount(0), sold(0){} 

        // Конструктор с параметрами 
        Product(int id,string name, double price, double selfprice, int amount, int sold) 
            : id(id), name(name), price(price), selfprice(selfprice), amount(amount), sold(sold) {} 

        // Геттер для id 
        int getId(){return id;} 
        // Сеттер для id 
        void setId(int id1){id = id1;} 
        // Геттер для name 
        string getName(){return name;} 
        // Сеттер для name 
        void setName(string name1) {name = name1;} 
        double getPrice(){return price;} 
        // Сеттер для price 
        void setPrice(double price1){price = price1;} 
        // Геттер для selfprice 
        double getSelfPrice(){return selfprice;} 
        // Сеттер для selfprice 
        void setSelfPrice(double selfprice1) {selfprice = selfprice1;} 
        int getAmount(){return amount;}
        void setAmount(int amount1){amount = amount1;}
        int getSold(){return sold;}
        void setSold(int sold1){sold = sold1;}
        // Метод для отображения информации о товаре 
        void displayInfo() const { 
            cout << "Product ID: " << id << endl; 
            cout << "Name: " << name << endl; 
            cout << "Price: " << price << endl; 
            cout << "Self Price: " << selfprice << endl; 
            cout << "Amount: " << amount << endl; 
            cout << "Sold: " << sold << endl; 
        } 
    }; 

// Предварительное объявление функций
void Menu(Product& MyProd, list<Product>& products,User &MyUser);
list<Product> generateCatalog();
void displayCatalogue(const list<Product>& products);
Product generateProduct(list<string>& adjective, list<string>& noun);

// Класс для представления пользователя



// Функция для генерации случайного товара
Product generateProduct(list<string>& adjective, list<string>& noun) {
    // Выбор случайного прилагательного
    int adjIndex = rand() % adjective.size();
    auto adjIt = adjective.begin();
    advance(adjIt, adjIndex); // Перемещаем итератор на случайный элемент
    string adj = *adjIt; // случайное прилагательное
    adjective.erase(adjIt); // Удаляем использованное прилагательное

    // Выбор случайного существительного
    int nounIndex = rand() % noun.size();
    auto nounIt = noun.begin();
    advance(nounIt, nounIndex); // Перемещаем итератор на случайный элемент
    string n = *nounIt; // Получаем случайное существительное
    noun.erase(nounIt); // Удаляем использованное существительное

    // Генерация случайных значений для товара
    int id = rand() % 101;
    double price = rand() % 251;
    double selfprice = rand() % 251;
    int amount = rand()%11;
    int sold = rand()%11;

    string name = adj + " " + n;

    return Product(id, name, price, selfprice,amount,sold); 
}

// Функция для генерации каталога
list<Product> generateCatalog() {
//метод для создания рандомных товаров и запихивания их в каталог 
    srand(static_cast<unsigned int>(time(0)));//что бы генерация рандомная работала корректно 
    int chance;  
    int id; 
    double price; 
    double selfprice; 
    int amount;
    int sold;
    list<Product> products; 
    list<string> name; 
    list<string> adjective = {"tasty", "salty", "wonderful", "fresh", "sweet"}; 
    list<string> noun = {"banana", "apple", "chips", "olives", "bread"}; 

    for (const auto i : adjective)// генерация названий товаров 
    { 
        for (const auto j : noun) 
        { 
            chance = rand() %26; 
            if (chance > 12) 
            { 
            name.push_front(i+" "+j); 
            }         
        } 
    } 
    for (const auto item : name ) //создание каталога 
    { 
        id = rand()%101; 
        price = rand()%251; 
        selfprice = rand()%251; 
        amount = rand()%11;
        sold = rand()%11;
        products.emplace_back(id, item, price, selfprice,amount,sold); 
    }
    return products;
}

// Функция для отображения каталога
void displayCatalogue(const list<Product>& products)
{
    int cat; 
    int numProd = 0;
    for (const auto& cat : products)
    {   
        numProd++; 
        cout << "================" << endl;     
        cout << "Product № " << numProd << endl; 
        cat.displayInfo(); 
        cout << endl; 
    } 
}
void AdminMenu(Product &MyProd, list<Product>& products,User &MyUser)
{   
    
    list<string> adjective = {"tasty", "salty", "wonderful", "fresh", "sweet"};
    list<string> noun = {"banana", "apple", "chips", "olives", "bread"};
    list<Product> basket;
    int choose;
    Product defaultProduct;
    string newUserName;
    string newPassword;
    string newPhoneNumber;
    do
    {
        cout << "============Welcome to admin's menu! Select an option============\n";
        cout << "1. Generate product\n";        
        cout << "2. Add an empty product in catalogue\n";
        cout << "3. Display catalogue info\n";  
        cout << "4. Remove last product in catalogue\n";  
        cout << "5. Add a new Admin\n";
        cout << "6. Add a new Cargo\n";
        cout << "7. Exit the Menu(logout)\n";
        cout << "=================================================================\n";        
        cin >> choose;
        switch (choose)
        {
        case 1:
            {     
            Product newProduct = generateProduct(adjective, noun);
            products.push_back(newProduct);
            cout << "New product added to the catalog!" << endl;
            break;
            }
        case 2:
            {
            products.push_back(defaultProduct);
            break;
            }
        case 3:                
            {
            displayCatalogue(products);                  
            break;
            }
        case 4:
            {
            products.pop_back();
            break;
            }
        case 5:
            {
            Admin MyAdmin;
            cout << "Enter a name: ";
            cin >> newUserName;
            MyAdmin.setUserName(newUserName);
            cout << "Enter a password: ";
            cin >> newPassword;
            MyAdmin.setPassword(newPassword);
            cout << "Enter a phone number";
            cin >> newPhoneNumber;
            MyAdmin.setPhoneNumber(newPhoneNumber); 
            MyAdmin.saveToFileAdmin();
            break;
            }
        case 6:
            {
            Cargo MyCargo;
            cout << "Enter a name: ";
            cin >> newUserName;
            MyCargo.setUserName(newUserName);
            cout << "Enter a password: ";
            cin >> newPassword;
            MyCargo.setPassword(newPassword);
            cout << "Enter a phone number";
            cin >> newPhoneNumber;
            MyCargo.setPhoneNumber(newPhoneNumber); 
            MyCargo.saveToFileCargo();
            break;
            }
        case 7:
            {                    
            cout << "Good bye!,Have a nice day<3" << endl;
            EnterUser(MyUser);
            return;
            }
        default:                
           {
           cout << "out of menu, try again" << endl;                
           }
        
        }     
    } while (choose != 000);
    
}
void CargoMenu(Product &MyProd, list<Product>& products,User &MyUser)
{   
    
    list<string> adjective = {"tasty", "salty", "wonderful", "fresh", "sweet"};
    list<string> noun = {"banana", "apple", "chips", "olives", "bread"};
    list<Product> basket;
    int choose;
    Product defaultProduct;
    string newUserName;
    string newPassword;
    string newPhoneNumber;
    do
    {
        cout << "============Welcome to admin's menu! Select an option============\n";
        cout << "1. Change an amount of product by number\n";        
        cout << "3. Display catalogue info\n";  
        cout << "3. Exit the Menu(logout)\n";
        cout << "=================================================================\n";        
        cin >> choose;
        switch (choose)
        {
        case 1:
            {        
            int productNumber;
            int newAmount;
            cout << "Enter the product number: ";
            cin >> productNumber;
            cout << "Enter the new amount: ";
            cin >> newAmount;

            if (productNumber > 0 && productNumber <= products.size()) {
                auto it = products.begin();
                advance(it, productNumber - 1); // Перемещаем итератор на нужный продукт
                it->setAmount(newAmount); // Устанавливаем новое количество
                cout << "Amount updated successfully!" << endl;
            } else {
                cout << "Invalid product number!" << endl;
            }
            break;
            }
        case 2:                
            {
            displayCatalogue(products);                  
            break;
            }
        case 3:
            {                    
            cout << "Good bye!,Have a nice day<3" << endl;
            EnterUser(MyUser);
            return;
            }
        default:                
           {
           cout << "out of menu, try again" << endl;                
           }
        
        }     
    } while (choose != 000);
    
}
void Menu(Product &MyProd, list<Product>& products,User &MyUser)
{
    list<string> adjective = {"tasty", "salty", "wonderful", "fresh", "sweet"};
    list<string> noun = {"banana", "apple", "chips", "olives", "bread"};
    list<Product> basket;
    int choose;
    Product defaultProduct;
    int basketChoose;
    int m;
    do
    {   
        cout << "============Welcome to menu! Select an option============\n";
        cout << "1. Add product in your basket by number\n";        
        cout << "2. Display catalogue info\n";   
        cout << "3. Display your basket info\n";  
        cout << "4. Buy all products in your basket\n";
        cout << "5. Remove last product in your basket\n";
        cout << "6. Exit the Menu(logout)\n";
        cout << "=================================================================\n";        
        cin >> choose;
        switch(choose){                 
            case 1:
                {
                cout << "Enter a number of adding product: ";
                cin >> basketChoose;
                basketChoose -= 1;
                auto it = products.begin();
                advance(it,basketChoose);
                basket.push_back(*it);
                break;
                }
            case 2:                
                {
                displayCatalogue(products);                  
                break;
                }
            case 3:
                {
                int cat; 
                int numProd = 0;
                for (const auto& cat : basket)
                {   
                    numProd++; 
                    cout << "================" << endl;     
                    cout << "Product Number: " << numProd << endl; 
                    cat.displayInfo(); 
                    cout << endl; 
                } 
                break;
                }
            case 4:
                {
                bool purchaseSuccessful = true;
                if (basket.empty()) {
                    cout << "Basket is empty! Add products to the basket first." << endl;
                    break;
                }
                for (auto& item : basket) {
                    if (item.getAmount() <= 0) {
                        cout << "Product " << item.getName() << " is out of stock!" << endl;
                        purchaseSuccessful = false;
                        break;
                    }
                }
                if (purchaseSuccessful) {
                    for (auto& basketItem : basket) {
                        for (auto& product : products) {
                            if (product.getId() == basketItem.getId()) { 
                                product.setSold(product.getSold() + 1); 
                                product.setAmount(product.getAmount() - 1); 
                                break;
                            }
                        }
                    }
                    cout << "Purchase successful! Thank you for your purchase!" << endl;
                    basket.clear(); 
                } else {
                    cout << "Purchase failed due to out of stock items!" << endl;
                }
                break;       
                }
            case 5:
                {                
                basket.pop_back();
                break;
                }
            case 6:
                {                    
                cout << "Good bye!,Have a nice day<3" << endl;
                EnterUser(MyUser);
                return;
                }

            default:                
                {
                cout << "out of menu, try again" << endl;                
                }
            }    
    }while(choose != 000);
}

void EnterUser(User &MyUser) // Метод авторизации
{
    string newUserName;
    string newPassword;
    string newPhoneNumber;
    string registration;
    string line;
    string role;
    string storedUserName;
    string storedPassword;
    bool found = false;

    cout << "You are a new user? (y/n): ";
    cin >> registration;

    if (registration == "n") {
        cout << "Enter your user role(client = c; cargo = s; admin = a)";
        cin >> role;
        if (role == "a")
        {
            cout << "Enter your name: ";
            cin >> newUserName;
            MyUser.setUserName(newUserName);
            cout << "Enter your password: ";
            cin >> newPassword;
            MyUser.setPassword(newPassword);

            ifstream file("admin.txt");
            if (!file.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
                return;
            }

            while (getline(file, line)) {
                if (line.find("Name: ") == 0) {
                    storedUserName = line.substr(6); // Извлекаем имя пользователя
                } else if (line.find("Password: ") == 0) {
                    storedPassword = line.substr(10); // Извлекаем пароль
                } else if (line.find("-----------------------------") == 0) {
                    // Проверяем, совпадают ли введенные данные с данными из файла
                    if (storedUserName == newUserName && storedPassword == newPassword) {
                        found = true;
                        break;
                    }
                    // Сбрасываем значения для следующего клиента
                    storedUserName.clear();
                    storedPassword.clear();
                }
            }

            file.close();

            if (found) {
                cout << "Welcome, " << newUserName << "!" << endl;
                list<Product> products = generateCatalog();
                Product MyProd1;
                AdminMenu(MyProd1, products, MyUser);
            } else {
                cout << "Неверный логин или пароль!" << endl;
            }
        }

        else if (role == "c")
        {
            cout << "Enter your name: ";
            cin >> newUserName;
            MyUser.setUserName(newUserName);
            cout << "Enter your password: ";
            cin >> newPassword;
            MyUser.setPassword(newPassword);

            ifstream file("clients.txt");
            if (!file.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
                return;
            }

            while (getline(file, line)) {
                if (line.find("Name: ") == 0) {
                    storedUserName = line.substr(6); // Извлекаем имя пользователя
                } else if (line.find("Password: ") == 0) {
                    storedPassword = line.substr(10); // Извлекаем пароль
                } else if (line.find("-----------------------------") == 0) {
                    // Проверяем, совпадают ли введенные данные с данными из файла
                    if (storedUserName == newUserName && storedPassword == newPassword) {
                        found = true;
                        break;
                    }
                    // Сбрасываем значения для следующего клиента
                    storedUserName.clear();
                    storedPassword.clear();
                }
            }

            file.close();

            if (found) {
                cout << "Welcome, " << newUserName << "!" << endl;
                list<Product> products = generateCatalog();
                Product MyProd1;
                Menu(MyProd1, products, MyUser);
            } else {
                cout << "Неверный логин или пароль!" << endl;
            }
        }
        else if (role == "s")
        {
            cout << "Enter your name: ";
            cin >> newUserName;
            MyUser.setUserName(newUserName);
            cout << "Enter your password: ";
            cin >> newPassword;
            MyUser.setPassword(newPassword);

            ifstream file("cargo.txt");
            if (!file.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
                return;
            }

            while (getline(file, line)) {
                if (line.find("Name: ") == 0) {
                    storedUserName = line.substr(6); // Извлекаем имя пользователя
                } else if (line.find("Password: ") == 0) {
                    storedPassword = line.substr(10); // Извлекаем пароль
                } else if (line.find("-----------------------------") == 0) {
                    // Проверяем, совпадают ли введенные данные с данными из файла
                    if (storedUserName == newUserName && storedPassword == newPassword) {
                        found = true;
                        break;
                    }
                    // Сбрасываем значения для следующего клиента
                    storedUserName.clear();
                    storedPassword.clear();
                }
            }

            file.close();

            if (found) {
                cout << "Welcome, " << newUserName << "!" << endl;
                list<Product> products = generateCatalog();
                Product MyProd1;
                CargoMenu(MyProd1, products, MyUser);
            } else {
                cout << "Неверный логин или пароль!" << endl;
            }
        }
    } else if (registration == "y") {
        
        cout << "Enter your name: ";
        cin >> newUserName;
        MyUser.setUserName(newUserName);
        cout << "Enter your password: ";
        cin >> newPassword;
        MyUser.setPassword(newPassword);
        Client MyClient;
        MyClient.setUserName(newUserName); // Устанавливаем имя пользователя
        MyClient.setPassword(newPassword); // Устанавливаем пароль

        string NewAddress;
        string NewEmail;
        cout << "Enter an email: ";
        cin >> NewEmail;
        MyClient.setEmail(NewEmail);
        cout << "Enter an address: ";
        cin >> NewAddress;
        MyClient.setAddress(NewAddress);

        // Сохраняем данные клиента в файл
        MyClient.saveToFile();
        cout << "Регистрация завершена!" << endl;
    } else {
        cout << "Некорректный выбор. Попробуйте снова." << endl;
    }
}

int main() {
    User defaultUser;
    EnterUser(defaultUser);
    return 0;
}