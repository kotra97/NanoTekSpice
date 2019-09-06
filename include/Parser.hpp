//
// Parser.hpp for parser in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Tue Jan 24 14:31:43 2017 Kotra
// Last update Sat Mar  4 13:57:43 2017 Kotra
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "IComponent.hpp"
#include "CompoManager.hpp"
#include "Pin.hpp"
#include "chipset.hpp"
#include "IParser.hpp"

#define BAD_FILE "The circuit file includes one or several lexical errors or syntactic errors"
#define UKWN_TYPE "A component type is unknown"
#define UKNW_NAME "A component name is unknown"
#define NO_PIN "The given pin does not exist"
#define SAME_NAME "Several components share the same name"
#define NO_LINK "Not every output is linked"
#define NO_INPUT "Missing input value on command line"
#define UKNW_INPUT "Unknown input specified by command line"
#define NO_CHIP "No chipset section"
#define NO_LINKS "No links section"

typedef struct s_output
{
  nts::IComponent *compo;
  nts::Tristate state;
  std::string name;
}t_output;

class Parser : public nts::IParser
{
private:
  CompoManager _manager;
  std::vector<std::string> _name;
  std::vector<nts::IComponent *> _compo;
  std::vector<chipset *> _input;
  std::vector<chipset *> _clock;
  std::vector<chipset *> _terminal;
  std::vector<t_output> _output;
protected:
public:
  Parser();
  ~Parser();
  void check_arg_chip(std::string name, std::string type);
  void check_arg_link(std::string name, std::string type);
  void display();
  void simulate(int i = 1);
  void dump();
  void loop();
  void SetInput(std::string);
  void feed(std::string const& input);
  void parseTree(nts::t_ast_node& root){(void)root;};
  nts::t_ast_node *createTree(){return (NULL);};
};

#endif
