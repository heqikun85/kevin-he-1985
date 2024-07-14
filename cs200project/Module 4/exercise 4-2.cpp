Square::Square(vector<string> tokens)
{
	//initializing side
	side = tokens.size() >= 2 ? std::stod(tokens[1]) : 0;	
}

// Constructor for Sqaure objects taking vector of string as its argument

square(vector<string> tokens) 
{

	//tokens[1] contains the side dimension, as it is in string, it needs to be explicitly converted to float value

	side = std::atof(tokens[1]);

	// at index 0, shape of the object is specified

	shape = tokens[0];

}
