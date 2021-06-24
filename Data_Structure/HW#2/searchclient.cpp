#include "search.cpp"

int main(int argc, char *argv[]) {
    Search *search;
    int num;
    int column = atoi(argv[2]);

    // argc가 4일 때만 실행시킴
    if(argc == 4) {
        // column number 범위는 0보다 크거나 같고 3보다 작거나 같음
        if(column >= 0 && column <= 3) {

            search->read_data(argv[1], &search, &num);                        // argv[1]을 통해 파일 불러오기
            search->sort_data(search, column, num);                           // 오름차순으로 정렬시킴
            int idx = search->binsearch(search, argv[3], 0, num-1, column);   // argv[3]과 동일한 내용을 저장하는 idx 반환

            if(idx < 0) {                                               
                printf("%s Not Found!!\n", argv[3]);                           // idx가 0보다 작으면 Not Found 출력
                printf("\n");
            } else {
                search->print_data(search, idx);                              // 해당 idx 정보 출력
            }
        }
        else {
            printf("Column range should be 0 ~ 3!\n\n");
        }
    }
    else {
        printf("Usage:  search.exe <Data File> <Column Number> <Search Data>\n\n");
    }
    return 0; 
}