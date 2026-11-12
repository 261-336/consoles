#include <iostream>
#include <sstream>
#include <iomanip>
#include <iterator>
using namespace std;

enum ConsoleType {
    Dedicated,
    Home,
    Handheld,
    Home_add_on,
    Hybrid
};

struct Console {
    string name;
    ConsoleType type;
    string company_name;
    int release_year;
    int discontinuation_year;
    double units_sold_mil;
    string remarks;
};

// https://www.kaggle.com/datasets/tayyarhussain/best-selling-game-consoles-of-all-time?resource=download
Console consoles[] = {
    {"PlayStation 2", Home, "Sony", 2000, 2013, 155, "Final sales are greater than 155 million"},
    {"Nintendo DS", Handheld, "Nintendo", 2004, 2013, 154.02, ""},
    {"Nintendo Switch", Hybrid, "Nintendo", 2017, 0, 122.55, ""},
    {
        "Game Boy", Handheld, "Nintendo", 1989, 2003, 64.42,
        "The Game Boy (1989) and the Game Boy Color (1998) combined have sold 118.69 million units worldwide"
    },
    {"Game Boy Color", Handheld, "Nintendo", 1998, 2003, 44.06, ""},
    {"PlayStation 4", Home, "Sony", 2013, 0, 117.2, ""},
    {"PlayStation", Home, "Sony", 1994, 2006, 102.49, ""},
    {"Wii", Home, "Nintendo", 2006, 2013, 101.63, ""},
    {"PlayStation 3", Home, "Sony", 2006, 2017, 87.4, "Final sales are greater than 87.4 million"},
    {"Xbox 360", Home, "Microsoft", 2005, 2016, 84, "Final sales are greater than 84 million"},
    {"Game Boy Advance", Handheld, "Nintendo", 2001, 2010, 81.51, ""},
    {"PlayStation Portable", Handheld, "Sony", 2004, 2014, 82, "Estimated between 80-82 million"},
    {"Nintendo 3DS", Handheld, "Nintendo", 2011, 2020, 75.94, ""},
    {"NES/Famicom", Home, "Nintendo", 1983, 2003, 61.91, ""},
    {"Xbox One", Home, "Microsoft", 2013, 2020, 58.5, "Estimated between 51-58.5 million"},
    {"SNES/Super Famicom", Home, "Nintendo", 1990, 2003, 49.1, ""},
    {"Game & Watch", Handheld, "Nintendo", 1980, 1991, 43.4, ""},
    {"Nintendo 64", Home, "Nintendo", 1996, 2002, 32.93, ""},
    {"Sega Genesis/Mega Drive", Home, "Sega", 1988, 1997, 30.75, ""},
    {"PlayStation 5", Home, "Sony", 2020, 0, 30, ""},
    {"Atari 2600", Home, "Atari", 1977, 1992, 30, ""},
    {"Xbox", Home, "Microsoft", 2001, 2009, 24, ""},
    {"GameCube", Home, "Nintendo", 2001, 2007, 21.74, ""},
    {"Xbox Series X/S", Home, "Microsoft", 2020, 0, 18.5, "Approximately around 18.5 million"},
    {"Wii U", Home, "Nintendo", 2012, 2017, 13.56, ""},
    {"PlayStation Vita", Handheld, "Sony", 2011, 2019, 15, "Estimated between 10-15 million"},
    {
        "Sega Master System", Home, "Sega", 1986, 1996, 13,
        "Estimated between 10 - 13 million. Fun Fact The Sega Master System was never discontinued, they're still making them in Brazil."
    },
    {"Sega Game Gear", Handheld, "Sega", 1990, 1997, 10.62, ""},
    {"PC Engine/TurboGrafx-16", Home, "NEC/Hudson Soft[note 6]", 1987, 1994, 10, ""},
    {"Sega Saturn", Home, "Sega", 1994, 2000, 9.26, ""},
    {"Dreamcast", Home, "Sega", 1998, 2001, 9.13, ""},
    {"Master System(Brazilian variants)", Home, "Tectoy", 1989, 1996, 8, ""},
    {"Dendy(Famiclone)", Home, "Micro Genius", 1992, 1998, 6, ""},
    {"Super NES Classic Edition", Dedicated, "Nintendo", 2017, 2018, 5.28, ""},
    {"Famicom Disk System", Home_add_on, "Nintendo", 1986, 1992, 4.5, ""},
    {"NES Classic Edition", Dedicated, "Nintendo", 2016, 2018, 3.56, ""},
    {"WonderSwan", Handheld, "Bandai", 1999, 2018, 3.5, ""},
    {"Sega Pico", Home, "Sega", 1993, 1998, 3.4, "Final sales are greater than 3.4 million"},
    {"Color TV-Game", Dedicated, "Nintendo", 1977, 1980, 3, ""},
    {"Intellivision", Home, "Mattel", 1980, 1990, 3, ""},
    {"Mega Drive(Brazilian variants)", Home, "Tectoy", 1990, 1996, 3, ""},
    {"N-Gage", Handheld, "Nokia", 2003, 2005, 3, ""},
    {"Sega CD", Home_add_on, "Sega", 1991, 1996, 2.24, ""},
    {"ColecoVision", Home, "Coleco", 1982, 1985, 2, "Final sales are greater than 2 million"},
    {"Magnavox Odyssey", Home, "Magnavox/Philips", 1978, 1975, 2, ""},
    {"PC Engine CD-ROM", Home_add_on, "NEC", 1988, 1998, 1.92, ""},
    {"Atari 7800", Home, "Atari", 1986, 1991, 1, "Final sales are greater than 1 million"},
    {"Atari Lynx", Handheld, "Atari", 1989, 1995, 1, "Final sales are greater than 1 million"},
    {"Philips CD-i", Home, "Philips", 1990, 1998, 1, "Final sales are greater than 1 million"},
    {"Telstar", Dedicated, "Coleco", 1976, 1978, 1, "Final sales are greater than 1 million"},
    {"Atari 5200", Home, "Atari", 1982, 1984, 1, "Final sales are greater than 1 million"},
};

string console_type_to_string(ConsoleType consle_type) {
    switch (consle_type) {
    case Dedicated: return "Dedicated";
    case Home: return "Home";
    case Handheld: return "Handheld";
    case Home_add_on: return "Home consol add-on";
    case Hybrid: return "Hybrid";
    default: return "Unknown";
    }
}

string console_to_string(Console& console) {
    stringstream ss;
    ss << std::left << setw(33) << console.name << " ";
    ss << std::left << setw(18) << console_type_to_string(console.type) << " ";
    ss << std::left << setw(23) << console.company_name << " ";
    string discontinued = console.discontinuation_year == 0 ? "present" : to_string(console.discontinuation_year);
    ss << console.release_year << "-" << std::left << setw(7) << discontinued << " ";
    ss << console.units_sold_mil;

    return ss.str();
}

void list() {
    size_t consolesSize = std::size(consoles);

    for (int i = 0; i < consolesSize; i++) {
        cout << setw(2) << i + 1 << " " << console_to_string(consoles[i]) << endl;
    }
}

void list_backwards() {
    size_t consolesSize = std::size(consoles);

    for (int i = consolesSize - 1; i >= 0; i--) {
        cout << setw(2) << consolesSize - i << " " << console_to_string(consoles[i]) << endl;
    }
}

// добавьте свою функцию здесь

void list_longest() {
    size_t conolesSize = std::size(consoles); // Вычисляем длину всего массива
    size_t max_lengh = 0; // Считаем максимальную длнину  названия консоли
    int longest_index = -1; // Определяем индекс подходящей под условие консоли
    for (size_t i = 0; i < conolesSize; i++) {
        size_t currect_lenght = consoles[i].name.length();
        if (currect_lenght > max_lengh) {
            max_lengh = currect_lenght;
            longest_index = i;

        }
    }
    if (longest_index != -1) {
        cout << "Самое длинное имя консоли: " << consoles[longest_index].name << endl;
        cout << "Длина ее названия: " << max_lengh << endl;
    }
    else {
        cout << "Массив консолей пуст." << endl;
    }
}

enum Command {
    List,
    ListBackwards,
    ListLongest,  // добавьте сюда идентификатор команды
    Exit
};

string command_description(Command command) {
    switch (command) {
    case List: return "Вывести список консолей";
    case ListBackwards: return "Вывести список консолей в обратном порядке";
    case ListLongest: return "Выводит самое длинное название консоли"; // добавьте сюда описание команды
    case Exit: return "Выход";
    default:
        stringstream ss;
        ss << "Команда №" << std::to_string(command);
        return ss.str();
    }
}

void perform_command(Command command) {
    switch (command) {
    case List:
        list();
        break;
    case ListBackwards:
        list_backwards();
        break;
    case ListLongest: // добавьте вызов своей функции здесь. не забудьте break
        list_longest();
        break;
    default:
        cout << "Действие команды не определено" << endl;
    }
}


int main(int, char**) {
    std::setlocale(LC_ALL, "RU_ru.UTF-8")
    bool cont = true;

    while (cont) {
        cout << endl << "Выберите номер команды" << endl;

        int commandNumber = -1;
        do {
            commandNumber++;
            cout << setw(2) << commandNumber << " ";
            cout << command_description(static_cast<Command>(commandNumber)) << endl;
        } while (commandNumber != Command::Exit);

        int selectedCommand;
        cin >> selectedCommand;

        if (selectedCommand == Command::Exit) {
            cont = false;
        }
        else {
            perform_command(static_cast<Command>(selectedCommand));
        }
    }
}
