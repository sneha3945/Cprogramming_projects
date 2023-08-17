#include <stdio.h>
#include <stdlib.h>

// Structure to hold the conversion data
struct ConversionData {
    int bsYear;
    int adYear;
};

// Function to load conversion data from a file
void loadConversionData(struct ConversionData data[], int size, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d %d", &data[i].bsYear, &data[i].adYear) != 2) {
            fprintf(stderr, "Error reading data from file\n");
            exit(1);
        }
    }

    fclose(file);
}

// Function to convert BS year to AD year
int convertToAD(struct ConversionData data[], int size, int bsYear) {
    for (int i = 0; i < size; i++) {
        if (data[i].bsYear == bsYear) {
            return data[i].adYear;
        }
    }
    return -1; // Not found
}

int main() {
    const int dataSize = 10; // Adjust this based on your data
    struct ConversionData conversionData[dataSize];
    loadConversionData(conversionData, dataSize, "conversion_data.txt"); // Update filename

    int bsYear;
    printf("Enter BS year: ");
    scanf("%d", &bsYear);

    int adYear = convertToAD(conversionData, dataSize, bsYear);
    if (adYear != -1) {
        printf("Equivalent AD year is: %d\n", adYear);
    } else {
        printf("No conversion data found for the given BS year.\n");
    }

    return 0;
}
