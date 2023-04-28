#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
//
//            << "W jakim języku chcesz grać> pl (polskim) lub en (angielskim)\nChose language PL (polish) or EN (english)\n";
//    std::string language;
//    std::cin >> language;
    std::cout << "Podaj swoje imię.\n";
    std::string name;
    std::cin>>name;

    std::ifstream file("questionspl.csv");
//    script.open("questions" + language + ".csv");

    bool isWordSavedForBillGates = true;

    std::string row;
    while (getline(file, row)) {
        std::string questionId;
        std::string question, correctAnswer;
        std::string answers[4];
        std::string *pAnswers = answers;

        std::stringstream stringStream(row);
        std::getline(stringStream, questionId, ';');
        std::getline(stringStream, question, ';');
        std::getline(stringStream, *pAnswers, ';');
        std::getline(stringStream, *(pAnswers + 1), ';');
        std::getline(stringStream, *(pAnswers + 2), ';');
        std::getline(stringStream, *(pAnswers + 3), ';');
        std::getline(stringStream, correctAnswer, ';');

        std::cout << questionId << ". " << question << "\n1) " << *answers << "\n2) " << *(answers + 1) << "\n3) "
                  << *(pAnswers + 2) << "\n4)" << *(pAnswers + 3);

        int answer;
        std::cin >> answer;
        system("cls");
        system("clear");
        if (*(answers + answer - 1) == correctAnswer) {
            std::cout
                    << " udał ci się poprawnie odpowiedzieć nadal żyjesz. Do zobaczenia w kolejnej rundzie\n\n\n\n";
        } else {
            isWordSavedForBillGates = false;
            std::cout
                    << "Jak by to delikatnie powiedzieć?\nO już wiem.\nTux przestał przypominać siebie!\nDoprowadziłeś do jego śmierci.\nRuch oporu przeciwko Bilowi Gatesowi i jego planom na zniewolenie świata. Upadł, ponieważ zabiłeś jego przywódcę\nTeraz nik go już nie powstrzyma wszyscy skończymy jako jego niewolnicy.";
            break;
        }
    }
    file.close();

    if (isWordSavedForBillGates){
        system("cls");
        system("clear");
        std::cout << "Brawo " << name << ", udało ci się ocalić świat przed złym wrednym Billem Gatesem.\n";
    }
    return 0;
}
