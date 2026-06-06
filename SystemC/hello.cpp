#include <systemc.h>

SC_MODULE(Hello) {
  void say_hello() {
    cout << "Hello from SystemC @ " << sc_time_stamp() << endl;
  }

  SC_CTOR(Hello) {
    SC_THREAD(say_hello);
  }
};

int sc_main(int argc, char* argv[]) {
  Hello h("h");
  sc_start();
  return 0;
}