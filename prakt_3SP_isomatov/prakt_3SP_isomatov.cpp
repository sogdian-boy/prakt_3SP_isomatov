#include <iostream>
union FullInfo {
    char parents[2][50];
    int passport;
};
struct Person
{
    char name[50];
    long int age;
    FullInfo info;
};
int main()
{
    int n;
    std::cout << "Enter humans count: ";
    std::cin >> n;
    std::cin.ignore();
    Person all[100];
    Person adults[100];
    int adultsCount = 0;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter FIO: ";
        std::cin.getline(all[i].name, 50);
        std::cout << "Enter age: ";
        std::cin >> all[i].age;
        std::cin.ignore();
        if (all[i].age < 16)
        {
            std::cout << "Enter fathers FIO: ";
            std::cin.getline(all[i].info.parents[0],50);
            std::cout << "Enter mothers FIO: ";
            std::cin.getline(all[i].info.parents[1],50);
        }
        else
        {
            std::cout << "Enter passport number: ";
            std::cin >> all[i].info.passport;
            std::cin.ignore();
            adults[adultsCount++]=all[i];
        }
        std::cout << "\n---"<<std::endl;
    }
    for (int i = 0; i < adultsCount-1; i++)
    {
        for (int j = 0; j < adultsCount - i - 1; j++)
        {
            if (adults[j].info.passport > adults[j + 1].info.passport)
            {
                Person temp = adults[j];
                adults[j] = adults[j + 1];
                adults[j + 1] = temp;
            }
        }
    }
    std::cout << "\nAll 16+:" << std::endl;
    for (int i = 0; i < adultsCount; i++)
    {
        std::cout << adults[i].name << " | Age: " << adults[i].age << " | Passport: " << adults[i].info.passport << std::endl;
    }
}