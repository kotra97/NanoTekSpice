//
// IParser.hpp for IParser.hpp in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Wed Jan 25 14:08:08 2017 Kotra
// Last update Wed Feb  1 17:27:47 2017 Kotra
//

#ifndef IPARSER_HPP
# define IPARSER_HPP

#include <string>
#include <vector>

namespace nts
{
  enum class ASTNodeType : int
  {
    DEFAULT = -1,
    NEWLINE = 0,
    SECTION,
    COMPONENT,
    LINK,
    LINK_END,
    STRING
  };

  typedef struct s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children)
    : children(children) { }
    std::string lexeme;
    ASTNodeType type;
    std::string value;
    std::vector<struct s_ast_node*> *children;
  } t_ast_node;

  class IParser
  {
  public:
    virtual void feed(std::string const& input) = 0;
    virtual void parseTree(t_ast_node& root) = 0;
    virtual t_ast_node *createTree() = 0;
    virtual ~IParser(){};
  };
}

#endif //CPP_NANOTEKSPICE_PARSER_HPP
