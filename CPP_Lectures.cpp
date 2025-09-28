#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "동물이 소리를 냅니다." << endl; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "멍멍!" << endl; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "야옹!" << endl; }
};

int main() {
    Animal* p1 = new Dog();
    Animal* p2 = new Cat();

    p1->speak();  // 멍멍!
    p2->speak();  // 야옹!

    delete p1;
    delete p2;
}

// 상속(Inheritance)
// 표현법
// class <자식 클래스 이름> : <접근지정자> <부모 클래스 이름>
// 
// private : 직접 접근 X
// public : 접근 가능
// protected : 자식 클래스에서는 접근이 가능
// 가능하면 protected는 사용하려 하지 않을 것. 굉장히 취약한 형태
// 자식 클래스와 부모 클래스의 관계를 내가 전부 관리할 때만 사용. 자식만 보여줄 때
// 
// 상속 접근지정자: 부모 클래스가 가진 멤버를 지정한 형태로 가져오겠다는 의미
// private : 부모의 멤버에 직접 접근 불가
// portected, public : 부모의 private 빼곤 접근 가능 그러나 protected에는 함수를 통해서만 접근
// 
// 상속 접근지정자를 각각 private, protected, pulbic으로 하나씩 만들어 접근이 가능한지 확인하는 코드 작성
/*
#include <iostream>
using namespace std;

class Base {
int pri = 0;

public:
	int pub = 1;

protected:
	int pro = 2;
};

class Derived1 : private Base {


public:
	void show() {
		cout << pub << endl;
		cout << pro << endl;
		// cout << pri << endl; 프라이빗은 접근 불가
	}
};

class Derived2 : protected Base {


public:
	void show() {
		cout << pub << endl;
		cout << pro << endl;
		// cout << pri << endl;
	}
};

class Derived3 : public Base {


public:
	void show() {
		cout << pub << endl;
		cout << pro << endl;
		// cout << pri << endl;
	}
};

int main(int argc, char const* argv[])
{
	Derived1 one;
	Derived2 two;
	Derived3 thr;

	one.show();
	two.show();
	thr.show();

	thr.pub = 1;
	// two.pub = 1; protected에게 직접 접근은 X

	return 0;
}
*/
// 객체가 생성된다 = 객체가 들어갈 저장공간 할당 된 것(생성자는 이 순간에 호출)
// 자식 클래스가 생성되면 자동적으로 부모의 클래스 저장공간 할당이 된다
// 부모 클래스의 생성자를 자식 클래스에서 호출하여 생성자 작성이 가능(깃허브 자식 클래스 단일 상속 부분)
// ㄴ 초기화 리스트를 사용하는 것과 중괄호에서 작성하는 것의 차이를 조사할 것
// 
// 
// 다중 상속시 부모 클래스들이 같은 함수명을 가지고 있을 수도 있음. 누구의 함수인지 지정해야 함
// 
// 오버라이딩과 다형성에 대한 이야기. 하나의 형태가 여러개의...
// 이름은 같은 함수이나 저들의 영역은 각각이 다르다
// 깃허브의 오버라이딩 부분은 다형성에 대한 코드는 아님. 직접 만드는 코드에서 만들어보면 좋을 것
// 
// 2교시 실습때는 단일 상속, 다중 상속, 오버라이딩 부분을 가지고 놀아봤음
// 부모의 함수를 (1)프라이빗으로, (2)프로텍티드로
// 자식 클래스의 상속 접근 지정자를 (1)프라이빗으로, (2)프로텍티드로
// 다중 상속을 받을 때 부모 클래스에 같은 이름의 함수가 있다면 (5)어떻게?
// (6) 오버라이딩 관련 내용
// 불가능한 것이 있다면 어째서 불가능한지, 해결할 수 있는 문제는 어떻게 해결하면 좋을지 작성할 것
// 
/*
#include <iostream>
#include <string>
using namespace std;

// 부모 클래스 (기반 클래스)
class Person {
protected:
	string name;
	int age;


public:
	Person(string n, int a) : name(n), age(a) {}

	void introduce() { // 1. 컴파일 해보고 얘를 프라이빗, 프로텍티드로 바꿔보기
		cout << "이름: " << name << ", 나이: " << age << endl;
	}
};

// 자식 클래스 (파생 클래스)
class Student : public Person { // 2. 상속 접근지정자를 private, protected로 바꿔보기
private:
	string major;

public:
	Student(string n, int a, string m) : Person(n, a), major(m) {}

	void study() {
		cout << name << " 학생이 " << major << " 전공 공부 중입니다." << endl;
	}

};

int main() {
	Student s("홍길동", 21, "컴퓨터공학");
	s.introduce();   // 부모 클래스 함수 사용 // 1.1 인트로듀스를 프라이빗으로 바꾸면 직접 접근할 수 없을 것. 해결해보기
	s.study();       // 자식 클래스 함수 사용
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

class Teacher {
public:
	void teach() {
		cout << "강의를 하고 있습니다." << endl;
	}
};

class Researcher {
public:
	void research() {
		cout << "연구를 하고 있습니다." << endl;
	}
	void teach() { cout << "변수 발생" << endl; } // 스코프로 지정이 가능할까?
};

// 다중 상속
class Professor : public Teacher, public Researcher {
public:
	void introduce() {
		cout << "저는 교수입니다." << endl;
	}

};

int main() {
	Professor p;
	p.introduce();
	p.Teacher::teach(); // 이게 되네
	p.research();
	return 0;
}
*/
// 
// (1) 이건 솔직히 애매함 잘 모르겠음. 이름이 다른 새로운 함수를 정의하는 것 말고 방법이 없지 않나?
// (2) 이거 오버라이딩으로 원본의 함수를 스코프로 호출하면 가능하긴 함
// (3) 상속 접근 지정자를 프라이빗으로 바꾸면 또다시 introduce()를 사용할 수 없다. 그렇겠지 자식에선 접근할 수 없으니
// (4) 프로텍티드로 바꿔도 메인에서 introduce는 사용할 수 없음. 클래스 밖에서 보면 여전히 private으로 보이기 때문. 이건 자식 클래스에 무언가 추가해서 가능할지도
// (5) 스코프를 사용해 사용하려는 함수를 가진 클래스를 지정해주면 가능함!
// (6) 5번이 가능하면 저걸 이용해서 다형성을 표현할 수 있지 않을까?
// 
// 오버라이딩 한 사람은 대입 연산자를 써서 애니멀을 해보고 결과 보기?
// 애니멀이 독의 형태도 갖고 캣의 형태도 가질 수 있도록 만들려고 하는 것임
// 애니멀에 독이랑 캣을 대입연산자로 넣고 스피크 해보기(현상만 봐보고 더 공부할거면 해봐라)
// 
// 다음 시간까지 교수님이 클래스를 정의하면 그것을 만들 수 있을 만큼의 실력을 만들고 올 것
// 과제 제출시 깃허브 계정을 만들고 링크를 공유할 것
// 