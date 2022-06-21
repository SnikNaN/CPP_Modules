#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm &other)
{
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destroyed: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	Form("shrubbery creation", target, 145, 137)
{
	std::cout << "Created: ShrubberyCreationForm, target: " << target
		<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :
	Form(copy)
{}

void ShrubberyCreationForm::executeAct() const
{
	std::ofstream   file_out;

	std::cout << "executing..." << std::endl;
	file_out.open((getTarget() + "_shrubbery").c_str(),
				  std::ofstream::in | std::ofstream::trunc);

	file_out << "              _{\\ _{\\{\\/}/}/}__" << std::endl
		<<		"             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl
		<<		"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl
		<<		"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl
		<<		"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl
		<<		"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl
		<<		"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl
		<<		"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl
		<<		"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl
		<<		"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl
		<<		"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl
		<<		"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl
		<<		"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl
		<<		"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl
		<<		"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl
		<<		"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl
		<<		"             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl
		<<		"              {){/ {\\/}{\\/} \\}\\}" << std::endl
		<<		"              (_)  \\.-'.-/" << std::endl
		<<		"          __...--- |'-.-'| --...__" << std::endl
		<<		"   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl
		<<		" -\"    ' .  . '    |.'-._| '  . .  '   ' '-" << std::endl
		<<		" .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl
		<<		"          ' ..     |'-_.-|" << std::endl
		<<		"  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl
		<<		"              .'   |'- .-|   '." << std::endl
		<<		"  ..-'   ' .  '.   `-._.-`   .'  '  - ." << std::endl
		<<		"   .-' '        '-._______.-'     '  ." << std::endl
		<<		"        .      ~," << std::endl
		<<		"    .       .   |\\   .    ' '-." << std::endl;

	file_out.close();
}