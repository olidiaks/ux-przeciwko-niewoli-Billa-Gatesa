#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
//    std::cout
//            << "W jakim języku chcesz grać> pl (polskim) lub en (angielskim)\nChose language PL (polish) or EN (english)\n";
//    std::string language;
//    std::cin >> language;

    std::ifstream file("questionspl.csv");
//    script.open("questions" + language + ".csv");


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
        if (*(answers + answer - 1) == correctAnswer) {
            std::cout
                    << "\n\n\n\nGratulację udał ci się poprawnie odpowiedzieć nadal żyjesz. Do zobaczenia w kolejnej rundzie\n\n\n\n";
        } else {
            std::cout
                    << "\n\n\n\nJak by to delikatnie powiedzieć?\nO już wiem.\nTux przestał przypominać siebie!\nDoprowadziłeś od jego śmierci.\nRuch oporu przeciwko Bilowi Gatesowi i jego planom na zniewolenie świata.\nTeraz nik go już nie powstrzyma wszyscy skończymy jako jego niewolnicy.";
        }
    }

    return 0;
}
