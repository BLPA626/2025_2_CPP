//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Rectangle {
//private:
//    int width;      // 가로 길이
//    int height;     // 세로 길이
//
//public:
//    Rectangle(int w, int h) : width(w), height(h) {}
//
//    // 넓이 계산 함수
//    int area() const {
//        return width * height;
//    }
//
//    // 정보 출력 함수
//    void print() const {
//        cout << "Width: " << width
//            << ", Height: " << height
//            << ", Area: " << area() << endl;
//    }
//};
//
//
//int main() {
//    // vector를 이용해 Rectangle 객체 저장
//    vector<Rectangle> rects;
//
//    // 다양한 사각형 추가
//    rects.push_back(Rectangle(3, 4));
//    rects.push_back(Rectangle(10, 2));
//    rects.push_back(Rectangle(5, 5));
//    rects.push_back(Rectangle(7, 8));
//
//    cout << "저장된 사각형 목록" << endl;
//    for (const auto& r : rects)
//        r.print();
//
//    // 넓이를 기준으로 벡터 정렬
//    sort(rects.begin(), rects.end(),
//        [](const Rectangle& a, const Rectangle& b) {
//            return a.area() < b.area();  // 오름차순 정렬
//        });
//
//    cout << "\n넓이 기준 정렬 후" << endl;
//    for (const auto& r : rects)
//        r.print();
//
//    // 가장 넓은 사각형 찾기
//    auto maxRect = max_element(
//        rects.begin(),
//        rects.end(),
//        [](const Rectangle& a, const Rectangle& b) {
//            return a.area() < b.area();
//        }
//    );
//
//    cout << "\n가장 넓은 사각형" << endl;
//    maxRect->print();
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm> // sort 사용 (중복 카운트 용)
//using namespace std;
//
//int main() {
//
//    vector<int> v;
//    int num;
//
//    // 1) 0이 입력될 때까지 정수를 입력받아 vector에 저장 (0은 저장하지 않음)
//    cout << "정수를 입력하세요 (0 입력 시 종료): ";
//    while (true) {
//        cin >> num;
//        if (num == 0) break;     // 0이 입력되면 종료
//        v.push_back(num);        // 0 제외하고 저장
//    }
//
//    cout << "\n--- 입력 완료 ---" << endl;
//
//    // 2) 키보드로부터 입력된 정수의 개수 출력
//    cout << "입력된 정수 개수: " << v.size() << "개" << endl;
//
//    // 3) vector에 저장된 정수들의 평균 계산
//    if (!v.empty()) {
//        int sum = 0;
//        for (int n : v) sum += n;    // 모든 원소 합 구하기
//        double avg = static_cast<double>(sum) / v.size();
//        cout << "정수들의 평균: " << avg << endl;
//    }
//    else {
//        cout << "입력된 값이 없어 평균을 구할 수 없습니다." << endl;
//    }
//
//    // 4) 같은 정수 값이 몇 개 입력되었는지 출력
//    cout << "\n--- 값이 몇 개씩 입력되었는지 출력 ---" << endl;
//
//    if (!v.empty()) {
//        // 먼저 정렬 → 같은 값들을 모아줌
//        sort(v.begin(), v.end());
//
//        int current = v[0];
//        int count = 1;
//
//        for (size_t i = 1; i < v.size(); i++) {
//            if (v[i] == current) {
//                count++; // 같은 값 추가
//            }
//            else {
//                cout << current << " : " << count << "개\n";
//                current = v[i];
//                count = 1;
//            }
//        }
//        // 마지막 값 출력
//        cout << current << " : " << count << "개\n";
//    }
//
//    return 0;
//}


#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> freq;   // key = 입력된 정수, value = 해당 정수의 중복 횟수

    cout << "정수를 입력하세요 (0 입력 시 종료): " << endl;

    while (true) {
        int x;
        cin >> x;
        if (x == 0) break;   // 0 입력 시 종료
        freq[x]++;          // map에 저장 (중복일 경우 자동 증가)
    }

    // 1. 입력된 정수의 개수(map의 멤버 함수 사용 → freq.size())
    cout << "\n입력된 서로 다른 정수의 개수: " << freq.size() << endl;

    // 2. 평균 구하기 (모든 정수의 값 * 등장 횟수 총합 ÷ (전체 입력된 횟수))
    int sum = 0;
    int total_count = 0;

    for (auto& p : freq) {
        sum += p.first * p.second;   // 정수 * 등장 횟수
        total_count += p.second;     // 전체 입력된 횟수
    }

    if (total_count > 0) {
        double average = (double)sum / total_count;
        cout << "입력된 정수들의 평균: " << average << endl;
    }

    // 3. 각 정수가 몇 번 입력되었는지 출력
    cout << "\n=== 정수 등장 횟수 ===" << endl;
    for (auto& p : freq) {
        cout << p.first << " : " << p.second << "번" << endl;
    }

    return 0;
}
