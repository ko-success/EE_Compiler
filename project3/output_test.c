#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirstDifferenceLine(const char *file1, const char *file2) {
    FILE *fp1, *fp2;
    int ch1, ch2;
    int line = 1;
    
    // 파일 열기
    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        perror("파일 열기 오류");
        return -1; // 파일 열기 실패
    }

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        perror("파일 열기 오류");
        fclose(fp1);
        return -1; // 파일 열기 실패
    }

    // 파일 내용 비교
    while ((ch1 = fgetc(fp1)) != EOF && (ch2 = fgetc(fp2)) != EOF) {
        if (ch1 != ch2) {
            fclose(fp1);
            fclose(fp2);
            return line;
        }
        if (ch1 == '\n') {
            line++;
        }
    }

    if (ch1 != ch2) {
        fclose(fp1);
        fclose(fp2);
        return line;
    }

    // 파일 끝까지 비교 완료
    fclose(fp1);
    fclose(fp2);

    return 0; // 두 파일이 완전히 동일함
}

int main() {
    const char *file1 = "output.txt"; // 비교할 첫 번째 파일
    const char *file2 = "output_.txt"; // 비교할 두 번째 파일

    int result = findFirstDifferenceLine(file1, file2);

    if (result == 0) {
        printf("두 파일은 동일합니다.\n");
    } else if (result > 0) {
        printf("두 파일은 %d번째 줄에서 다릅니다.\n", result);
    } else {
        printf("파일 비교 중 오류가 발생했습니다.\n");
    }

    return 0;
}
