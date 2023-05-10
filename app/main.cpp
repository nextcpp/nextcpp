import utils;

int main() {

	utty::print("utty::print() is ok;", " Good!");
	utty::print("\n");
	utty::greet();
	utty::print("\nWhat about utty::print_a_truth()?\n");
	utty::print_a_truth();
	utty::print("Testing utty::print(utty::my_int(false)) - do we get 42?\n");
	utty::print(std::to_string(utty::my_int(false)));
	utty::print("\n");
	utty::print("That's it. Bye!");

	// Uncomment the next line and build the code to see what happens ^^
	//int i;
}
