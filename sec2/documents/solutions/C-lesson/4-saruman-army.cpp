#include<stdio.h>



// �z��𕪊�����֐�
int partition(int* arr, int low, int high) {
    int pivot = arr[high];  // �s�{�b�g�Ƃ��čŌ�̗v�f��I��
    int i = low - 1;  // �������v�f�̃C���f�b�N�X

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// �N�C�b�N�\�[�g�̃��C���֐�
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // ������̔z����ċA�I�Ƀ\�[�g
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int* ArrangeArray(int* arrayInput, int sizeArray) {
    int* arrayOutput = { };
    quickSort(arrayInput, 0, sizeArray - 1);
    for (int i = 0; i < sizeArray; i++) {
        printf("%d\n", arrayInput[i]);
    }
    return arrayInput;
}