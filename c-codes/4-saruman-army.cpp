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
    // ���Ԃ�����low = high�Ȃ�A���ёւ��s�v
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
    return arrayInput;
}

// �T���}���A���S���Y��
int solve(int* arrayInput, int sizeArray, int rangeValid) {
    for (int i = 0; i < sizeArray; i++) {
        printf("%d ", arrayInput[i]);
    }
    printf("\n");
    int countSigning = 0;
    int indexCurrent = 0;
    while (indexCurrent < sizeArray) {
        // checking
        int positionSign = arrayInput[indexCurrent] + rangeValid;
        countSigning += 1;
        while (arrayInput[indexCurrent] < positionSign + rangeValid && indexCurrent < sizeArray) {
            indexCurrent++;
        }

    }
    
    return countSigning;
}

