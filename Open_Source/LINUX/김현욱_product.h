typedef struct {
    char name[20];
    int weight;
    int price;
    int star_grade;
    int count_star;
} Product;

int loadProduct(Product *p);                 // 파일에서 데이터를 읽어오는 함수
int selectProduct();                         // 메뉴를 불러주는 함수
int selectDataNum(Product *p, int index);    // 원하는 제품 리스트의 번호를 입력해주는 함수
int listProduct(Product *p, int index);      // 현재 등록되어 있는 모든 제품을 출력해주는 함수
int readProduct(Product *p);                 // 제품 하나를 출력해주는 함수
int addProduct(Product *p);                  // 제품을 추가해주는 함수
int updateProduct(Product *p);               // 선택한 메뉴의 제품을 새로운 제품으로 바꿔주는 함수
int saveProduct(Product *p, int index);      // 추가한 제품을 파일에 저장해주는 함수
void searchProduct(Product *p, int index);   // 제품 이름을 검색하는 함수
int deleteProduct(Product *p);               // 해당 제품을 제거해주는 함수

