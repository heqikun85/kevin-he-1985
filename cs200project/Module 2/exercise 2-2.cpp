if( token[0] == "SQUARE" )
{
	Square *sq = new Square();
	
	if(token.size() > 1) 
		sq->side = atoi(token[1].c_str()); 
	else
		sq->side = 0;
}
