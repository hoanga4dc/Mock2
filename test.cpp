#include"Controller.cpp"

int main() {
	shared_ptr<Controller> C(new Controller);
	C->Run();
	return 0;
}