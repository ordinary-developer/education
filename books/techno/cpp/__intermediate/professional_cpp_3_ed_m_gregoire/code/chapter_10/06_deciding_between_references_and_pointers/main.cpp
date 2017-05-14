#include <vector>

// C style function
void separateOddsAndEvens(const int arr[], int size, int** odds, 
        int* numOdds, int** evens, int* numEvens) 
{
    *numOdds = *numEvens = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) {
            ++(*numOdds);
        }
        else {
            ++(*numEvens);
        }
    }

    *odds = new int[*numOdds];
    *evens = new int[*numEvens];
    int oddsPos = 0, evensPos = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) {
            (*odds)[oddsPos++] = arr[i];
        }
        else {
            (*evens)[evensPos++] = arr[i];
        }
    }
}

void separateOddsAndEvens_2(const int arr[], int size, int*& odds,
        int& numOdds, int*& evens, int& numEvens)
{
    numOdds = numEvens = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) {
            ++numOdds;
        }
        else {
            ++numEvens;
        }
    }
    odds = new int[numOdds];
    evens = new int[numEvens];
    int oddsPos = 0, evensPos = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) {
            odds[oddsPos++] = arr[i];
        }
        else {
            evens[evensPos++] = arr[i];
        }
    }
}

void separateOddsAndEvens_3(const std::vector<int>& arr,
        std::vector<int>& odds, std::vector<int>& evens)
{
    int numOdds = 0, numEvens = 0;
    for (auto& i : arr) {
        if (i % 2 == 1) {
            ++numOdds;
        }
        else {
            ++numEvens;
        }
    }
    odds.reserve(numOdds);
    evens.reserve(numEvens);
    for (auto& i : arr) {
        if (i % 2 == 1) {
            odds.push_back(i);
        }
        else {
            evens.push_back(i);
        }
    }
}

auto main() -> int {
    int unSplit[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *oddNums, *evenNums;
    int numOdds, numEvens;
    separateOddsAndEvens(unSplit, 10, &oddNums, &numOdds, &evenNums, &numEvens);
    separateOddsAndEvens_2(unSplit, 10, oddNums, numOdds, evenNums, numEvens);

    std::vector<int> vecUnSplit = { 1, 2, 3, 4, 5, 6,7, 8, 9, 10};
    std::vector<int> odds, evens;
    separateOddsAndEvens_3(vecUnSplit, odds, evens);

    return 0;
}
