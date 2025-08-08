// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hpp"


// Unqualified %code blocks.
#line 38 "parser.y"

    #include "scanner.hpp"
    static auto yylex(Parser::value_type* yylval, Parser::location_type* yylloc, Scanner& lexer, Node* & ast_root) -> int
    {
        return lexer.yylex(yylval, yylloc);
    }

#line 54 "parser.tab.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 7 "parser.y"
namespace SimpleCompiler {
#line 147 "parser.tab.cpp"

  /// Build a parser object.
  Parser::Parser (Scanner &scanner_yyarg, Node* & ast_root_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      ast_root (ast_root_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param: // param
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declaration_no_semi: // declaration_no_semi
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expr: // assignment_expr
      case symbol_kind::S_logical_or_expr: // logical_or_expr
      case symbol_kind::S_logical_and_expr: // logical_and_expr
      case symbol_kind::S_equality_expr: // equality_expr
      case symbol_kind::S_relational_expr: // relational_expr
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_type: // type
        value.copy< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param: // param
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declaration_no_semi: // declaration_no_semi
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expr: // assignment_expr
      case symbol_kind::S_logical_or_expr: // logical_or_expr
      case symbol_kind::S_logical_and_expr: // logical_and_expr
      case symbol_kind::S_equality_expr: // equality_expr
      case symbol_kind::S_relational_expr: // relational_expr
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_type: // type
        value.move< Node* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param: // param
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declaration_no_semi: // declaration_no_semi
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expr: // assignment_expr
      case symbol_kind::S_logical_or_expr: // logical_or_expr
      case symbol_kind::S_logical_and_expr: // logical_and_expr
      case symbol_kind::S_equality_expr: // equality_expr
      case symbol_kind::S_relational_expr: // relational_expr
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param: // param
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declaration_no_semi: // declaration_no_semi
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expr: // assignment_expr
      case symbol_kind::S_logical_or_expr: // logical_or_expr
      case symbol_kind::S_logical_and_expr: // logical_and_expr
      case symbol_kind::S_equality_expr: // equality_expr
      case symbol_kind::S_relational_expr: // relational_expr
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_type: // type
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param: // param
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declaration_no_semi: // declaration_no_semi
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expr: // assignment_expr
      case symbol_kind::S_logical_or_expr: // logical_or_expr
      case symbol_kind::S_logical_and_expr: // logical_and_expr
      case symbol_kind::S_equality_expr: // equality_expr
      case symbol_kind::S_relational_expr: // relational_expr
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_type: // type
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param: // param
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declaration_no_semi: // declaration_no_semi
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expr: // assignment_expr
      case symbol_kind::S_logical_or_expr: // logical_or_expr
      case symbol_kind::S_logical_and_expr: // logical_and_expr
      case symbol_kind::S_equality_expr: // equality_expr
      case symbol_kind::S_relational_expr: // relational_expr
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_type: // type
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner, ast_root));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement_list: // statement_list
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param: // param
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declaration_no_semi: // declaration_no_semi
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_for_stmt: // for_stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_return_stmt: // return_stmt
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expr: // assignment_expr
      case symbol_kind::S_logical_or_expr: // logical_or_expr
      case symbol_kind::S_logical_and_expr: // logical_and_expr
      case symbol_kind::S_equality_expr: // equality_expr
      case symbol_kind::S_relational_expr: // relational_expr
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_arg_list: // arg_list
      case symbol_kind::S_type: // type
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: statement_list
#line 81 "parser.y"
                   {
        ast_root = new ProgramNode(yystack_[0].location.begin.line); 
        ast_root->children.push_back((yystack_[0].value.as < Node* > ())); 
    }
#line 885 "parser.tab.cpp"
    break;

  case 3: // statement_list: statement
#line 88 "parser.y"
              { 
        auto node = new StatementListNode(yystack_[0].location.begin.line); 
        node->children.push_back((yystack_[0].value.as < Node* > ())); 
        yylhs.value.as < Node* > () = (node); 
    }
#line 895 "parser.tab.cpp"
    break;

  case 4: // statement_list: statement_list statement
#line 93 "parser.y"
                               { 
        yylhs.value.as < Node* > () = (yystack_[1].value.as < Node* > ()); 
        yylhs.value.as < Node* > ()->children.push_back((yystack_[0].value.as < Node* > ())); 
    }
#line 904 "parser.tab.cpp"
    break;

  case 5: // statement: function_def
#line 100 "parser.y"
                 { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 910 "parser.tab.cpp"
    break;

  case 6: // statement: declaration
#line 101 "parser.y"
                  { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 916 "parser.tab.cpp"
    break;

  case 7: // statement: assignment
#line 102 "parser.y"
                 { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 922 "parser.tab.cpp"
    break;

  case 8: // statement: if_stmt
#line 103 "parser.y"
              { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 928 "parser.tab.cpp"
    break;

  case 9: // statement: for_stmt
#line 104 "parser.y"
               { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 934 "parser.tab.cpp"
    break;

  case 10: // statement: while_stmt
#line 105 "parser.y"
                 { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 940 "parser.tab.cpp"
    break;

  case 11: // statement: return_stmt
#line 106 "parser.y"
                  { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 946 "parser.tab.cpp"
    break;

  case 12: // statement: expression ';'
#line 107 "parser.y"
                     { 
        auto node = new ExpressionStmtNode(yystack_[1].location.begin.line); 
        node->children.push_back((yystack_[1].value.as < Node* > ())); 
        yylhs.value.as < Node* > () = (node); 
    }
#line 956 "parser.tab.cpp"
    break;

  case 13: // function_def: type IDENTIFIER '(' param_list ')' '{' statement_list '}'
#line 115 "parser.y"
                                                              {
        auto node = new FunctionDefNode(
            static_cast<TypeNode*>(yystack_[7].value.as < Node* > ())->type_value, yystack_[6].value.as < std::string > (), yystack_[7].location.begin.line);
        node->children.push_back((yystack_[7].value.as < Node* > ()));
        node->children.push_back(new IdentifierNode(
            yystack_[6].value.as < std::string > (), Type{BaseType::Void}, yystack_[7].location.begin.line)); // Type TBD for identifier
        node->children.push_back((yystack_[4].value.as < Node* > ()));
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 971 "parser.tab.cpp"
    break;

  case 14: // param_list: %empty
#line 128 "parser.y"
                { yylhs.value.as < Node* > () = new StatementListNode(yylhs.location.begin.line); }
#line 977 "parser.tab.cpp"
    break;

  case 15: // param_list: param
#line 129 "parser.y"
            { 
        auto node = new StatementListNode(yystack_[0].location.begin.line); 
        node->children.push_back((yystack_[0].value.as < Node* > ())); 
        yylhs.value.as < Node* > () = (node); 
    }
#line 987 "parser.tab.cpp"
    break;

  case 16: // param_list: param_list ',' param
#line 134 "parser.y"
                           { 
        yylhs.value.as < Node* > () = (yystack_[2].value.as < Node* > ()); 
        yylhs.value.as < Node* > ()->children.push_back((yystack_[0].value.as < Node* > ())); 
    }
#line 996 "parser.tab.cpp"
    break;

  case 17: // param: type IDENTIFIER
#line 141 "parser.y"
                    { 
        auto node = new ParamNode(
            static_cast<TypeNode*>(yystack_[1].value.as < Node* > ())->type_value, yystack_[0].value.as < std::string > (), yystack_[1].location.begin.line);
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        node->children.push_back(new IdentifierNode(
            yystack_[0].value.as < std::string > (), static_cast<TypeNode*>(yystack_[1].value.as < Node* > ())->type_value, yystack_[1].location.begin.line));
        yylhs.value.as < Node* > () = (node);
    }
#line 1009 "parser.tab.cpp"
    break;

  case 18: // declaration: declaration_no_semi ';'
#line 152 "parser.y"
                            { yylhs.value.as < Node* > () = (yystack_[1].value.as < Node* > ()); }
#line 1015 "parser.tab.cpp"
    break;

  case 19: // declaration_no_semi: type IDENTIFIER
#line 156 "parser.y"
                    { 
        auto node = new DeclarationNode(
            static_cast<TypeNode*>(yystack_[1].value.as < Node* > ())->type_value, yystack_[0].value.as < std::string > (), yystack_[1].location.begin.line);
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        node->children.push_back(new IdentifierNode(
            yystack_[0].value.as < std::string > (), static_cast<TypeNode*>(yystack_[1].value.as < Node* > ())->type_value, yystack_[1].location.begin.line));
        yylhs.value.as < Node* > () = (node);
    }
#line 1028 "parser.tab.cpp"
    break;

  case 20: // declaration_no_semi: type IDENTIFIER '=' expression
#line 164 "parser.y"
                                     { 
        auto node = new DeclarationNode(
            static_cast<TypeNode*>(yystack_[3].value.as < Node* > ())->type_value, yystack_[2].value.as < std::string > (), yystack_[3].location.begin.line);
        node->children.push_back((yystack_[3].value.as < Node* > ()));
        node->children.push_back(new IdentifierNode(
            yystack_[2].value.as < std::string > (), static_cast<TypeNode*>(yystack_[3].value.as < Node* > ())->type_value, yystack_[3].location.begin.line));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1042 "parser.tab.cpp"
    break;

  case 21: // assignment: assignment_expr ';'
#line 176 "parser.y"
                        { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1048 "parser.tab.cpp"
    break;

  case 22: // if_stmt: IF '(' expression ')' '{' statement_list '}'
#line 179 "parser.y"
                                                 { 
        auto node = new IfStmtNode(yystack_[6].location.begin.line);
        node->children.push_back((yystack_[4].value.as < Node* > ()));
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1059 "parser.tab.cpp"
    break;

  case 23: // if_stmt: IF '(' expression ')' '{' statement_list '}' ELSE '{' statement_list '}'
#line 185 "parser.y"
                                                                               { 
        auto node = new IfStmtNode(yystack_[10].location.begin.line);
        node->children.push_back((yystack_[8].value.as < Node* > ()));
        node->children.push_back((yystack_[5].value.as < Node* > ()));
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1071 "parser.tab.cpp"
    break;

  case 24: // for_stmt: FOR '(' for_init ';' expression ';' expression ')' '{' statement_list '}'
#line 195 "parser.y"
                                                                              {
        auto node = new ForStmtNode(yystack_[10].location.begin.line);
        node->children.push_back((yystack_[8].value.as < Node* > ()));
        node->children.push_back(yystack_[6].value.as < Node* > () ? (yystack_[6].value.as < Node* > ()) : new Node("empty", "", yystack_[10].location.begin.line));
        node->children.push_back(yystack_[4].value.as < Node* > () ? (yystack_[4].value.as < Node* > ()) : new Node("empty", "", yystack_[10].location.begin.line));
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1084 "parser.tab.cpp"
    break;

  case 25: // for_stmt: FOR '(' for_init ';' ';' expression ')' '{' statement_list '}'
#line 203 "parser.y"
                                                                     {
        auto node = new ForStmtNode(yystack_[9].location.begin.line);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[7].value.as < Node* > ()); 
        yylhs.value.as < Node* > ()->children.push_back(new Node("empty", "", yystack_[9].location.begin.line));
        yylhs.value.as < Node* > ()->children.push_back(yystack_[4].value.as < Node* > ()); 
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
    }
#line 1096 "parser.tab.cpp"
    break;

  case 26: // for_stmt: FOR '(' for_init ';' expression ';' ')' '{' statement_list '}'
#line 210 "parser.y"
                                                                     {
        auto node = new ForStmtNode(yystack_[9].location.begin.line);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[7].value.as < Node* > ()); 
        yylhs.value.as < Node* > ()->children.push_back(yystack_[5].value.as < Node* > ()); 
        yylhs.value.as < Node* > ()->children.push_back(new Node("empty", "", yystack_[9].location.begin.line)); 
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
    }
#line 1108 "parser.tab.cpp"
    break;

  case 27: // for_stmt: FOR '(' for_init ';' ';' ')' '{' statement_list '}'
#line 217 "parser.y"
                                                          {
        auto node = new ForStmtNode(yystack_[8].location.begin.line);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[6].value.as < Node* > ()); 
        yylhs.value.as < Node* > ()->children.push_back(new Node("empty", "", yystack_[8].location.begin.line)); 
        yylhs.value.as < Node* > ()->children.push_back(new Node("empty", "", yystack_[8].location.begin.line)); 
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
    }
#line 1120 "parser.tab.cpp"
    break;

  case 28: // for_init: %empty
#line 228 "parser.y"
                { yylhs.value.as < Node* > () = new Node("empty", "", yylhs.location.begin.line); }
#line 1126 "parser.tab.cpp"
    break;

  case 29: // for_init: declaration_no_semi
#line 229 "parser.y"
                          { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1132 "parser.tab.cpp"
    break;

  case 30: // for_init: expression
#line 230 "parser.y"
                 { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1138 "parser.tab.cpp"
    break;

  case 31: // while_stmt: WHILE '(' expression ')' '{' statement_list '}'
#line 234 "parser.y"
                                                    { 
        auto node = new WhileStmtNode(yystack_[6].location.begin.line);
        node->children.push_back((yystack_[4].value.as < Node* > ()));
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1149 "parser.tab.cpp"
    break;

  case 32: // return_stmt: RETURN ';'
#line 243 "parser.y"
               { yylhs.value.as < Node* > () = new ReturnStmtNode(yystack_[1].location.begin.line); }
#line 1155 "parser.tab.cpp"
    break;

  case 33: // return_stmt: RETURN expression ';'
#line 244 "parser.y"
                            { 
        auto node = new ReturnStmtNode(yystack_[2].location.begin.line);
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1165 "parser.tab.cpp"
    break;

  case 34: // expression: assignment_expr
#line 252 "parser.y"
                    { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1171 "parser.tab.cpp"
    break;

  case 35: // expression: logical_or_expr
#line 253 "parser.y"
                      { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1177 "parser.tab.cpp"
    break;

  case 36: // assignment_expr: IDENTIFIER '=' expression
#line 257 "parser.y"
                              { 
        yylhs.value.as < Node* > () = new AssignmentNode("assignment", yystack_[2].location.begin.line);
        yylhs.value.as < Node* > ()->children.push_back(new IdentifierNode(yystack_[2].value.as < std::string > (), Type{BaseType::Void}, yystack_[2].location.begin.line));
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); 
    }
#line 1187 "parser.tab.cpp"
    break;

  case 37: // logical_or_expr: logical_and_expr
#line 264 "parser.y"
                     { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1193 "parser.tab.cpp"
    break;

  case 38: // logical_or_expr: logical_or_expr OR logical_and_expr
#line 265 "parser.y"
                                          { 
        auto node = new BinaryOpNode("||", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1204 "parser.tab.cpp"
    break;

  case 39: // logical_and_expr: equality_expr
#line 274 "parser.y"
                  { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1210 "parser.tab.cpp"
    break;

  case 40: // logical_and_expr: logical_and_expr AND equality_expr
#line 275 "parser.y"
                                         { 
        auto node = new BinaryOpNode("&&", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1221 "parser.tab.cpp"
    break;

  case 41: // equality_expr: relational_expr
#line 284 "parser.y"
                    { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1227 "parser.tab.cpp"
    break;

  case 42: // equality_expr: equality_expr EQ relational_expr
#line 285 "parser.y"
                                       { 
        auto node = new BinaryOpNode("==", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1238 "parser.tab.cpp"
    break;

  case 43: // equality_expr: equality_expr NE relational_expr
#line 291 "parser.y"
                                       { 
        auto node = new BinaryOpNode("!=", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1249 "parser.tab.cpp"
    break;

  case 44: // relational_expr: arithmetic_expr
#line 300 "parser.y"
                    { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1255 "parser.tab.cpp"
    break;

  case 45: // relational_expr: relational_expr '<' arithmetic_expr
#line 301 "parser.y"
                                          { 
        auto node = new BinaryOpNode("<", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1266 "parser.tab.cpp"
    break;

  case 46: // relational_expr: relational_expr '>' arithmetic_expr
#line 307 "parser.y"
                                          { 
        auto node = new BinaryOpNode(">", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1277 "parser.tab.cpp"
    break;

  case 47: // relational_expr: relational_expr LE arithmetic_expr
#line 313 "parser.y"
                                         { 
        auto node = new BinaryOpNode("<=", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1288 "parser.tab.cpp"
    break;

  case 48: // relational_expr: relational_expr GE arithmetic_expr
#line 319 "parser.y"
                                         { 
        auto node = new BinaryOpNode(">=", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1299 "parser.tab.cpp"
    break;

  case 49: // arithmetic_expr: term
#line 328 "parser.y"
         { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1305 "parser.tab.cpp"
    break;

  case 50: // arithmetic_expr: arithmetic_expr '+' term
#line 329 "parser.y"
                               { 
        auto node = new BinaryOpNode("+", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1316 "parser.tab.cpp"
    break;

  case 51: // arithmetic_expr: arithmetic_expr '-' term
#line 335 "parser.y"
                               { 
        auto node = new BinaryOpNode("-", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1327 "parser.tab.cpp"
    break;

  case 52: // term: factor
#line 344 "parser.y"
           { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1333 "parser.tab.cpp"
    break;

  case 53: // term: term '*' factor
#line 345 "parser.y"
                      { 
        auto node = new BinaryOpNode("*", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1344 "parser.tab.cpp"
    break;

  case 54: // term: term '/' factor
#line 351 "parser.y"
                      { 
        auto node = new BinaryOpNode("/", yystack_[2].location.begin.line);
        node->children.push_back((yystack_[2].value.as < Node* > ()));
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1355 "parser.tab.cpp"
    break;

  case 55: // factor: IDENTIFIER
#line 360 "parser.y"
               { 
        yylhs.value.as < Node* > () = new IdentifierNode(yystack_[0].value.as < std::string > (), Type{BaseType::Void}, yystack_[0].location.begin.line); // Type TBD
    }
#line 1363 "parser.tab.cpp"
    break;

  case 56: // factor: NUMBER
#line 363 "parser.y"
             { 
        Type num_type = yystack_[0].value.as < std::string > ().find('.') != std::string::npos ? Type{BaseType::Float} : Type{BaseType::Int};
        yylhs.value.as < Node* > () = new NumberNode(yystack_[0].value.as < std::string > (), num_type, yystack_[0].location.begin.line);
    }
#line 1372 "parser.tab.cpp"
    break;

  case 57: // factor: CHAR_LITERAL
#line 367 "parser.y"
                   { yylhs.value.as < Node* > () = new CharLiteralNode(yystack_[0].value.as < std::string > (), yystack_[0].location.begin.line); }
#line 1378 "parser.tab.cpp"
    break;

  case 58: // factor: '(' expression ')'
#line 368 "parser.y"
                         { yylhs.value.as < Node* > () = (yystack_[1].value.as < Node* > ()); }
#line 1384 "parser.tab.cpp"
    break;

  case 59: // factor: function_call
#line 369 "parser.y"
                    { yylhs.value.as < Node* > () = (yystack_[0].value.as < Node* > ()); }
#line 1390 "parser.tab.cpp"
    break;

  case 60: // factor: '-' factor
#line 370 "parser.y"
                 { 
        auto node = new UnaryOpNode("-", yystack_[1].location.begin.line);
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1400 "parser.tab.cpp"
    break;

  case 61: // factor: '!' factor
#line 375 "parser.y"
                 { 
        auto node = new UnaryOpNode("!", yystack_[1].location.begin.line);
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1410 "parser.tab.cpp"
    break;

  case 62: // function_call: IDENTIFIER '(' arg_list ')'
#line 383 "parser.y"
                                { 
        auto node = new FunctionCallNode(yystack_[3].value.as < std::string > (), yystack_[3].location.begin.line);
        node->children.push_back(new IdentifierNode(
            yystack_[3].value.as < std::string > (), Type{BaseType::Void}, yystack_[3].location.begin.line)); // Type TBD
        node->children.push_back((yystack_[1].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1422 "parser.tab.cpp"
    break;

  case 63: // arg_list: %empty
#line 393 "parser.y"
                { yylhs.value.as < Node* > () = new StatementListNode(yylhs.location.begin.line); }
#line 1428 "parser.tab.cpp"
    break;

  case 64: // arg_list: expression
#line 394 "parser.y"
                 { 
        auto node = new StatementListNode(yystack_[0].location.begin.line);
        node->children.push_back((yystack_[0].value.as < Node* > ()));
        yylhs.value.as < Node* > () = (node);
    }
#line 1438 "parser.tab.cpp"
    break;

  case 65: // arg_list: arg_list ',' expression
#line 399 "parser.y"
                              { 
        yylhs.value.as < Node* > () = (yystack_[2].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back((yystack_[0].value.as < Node* > ()));
    }
#line 1447 "parser.tab.cpp"
    break;

  case 66: // type: INT
#line 406 "parser.y"
        { yylhs.value.as < Node* > () = new TypeNode(Type{BaseType::Int}, yystack_[0].location.begin.line); }
#line 1453 "parser.tab.cpp"
    break;

  case 67: // type: FLOAT
#line 407 "parser.y"
            { yylhs.value.as < Node* > () = new TypeNode(Type{BaseType::Float}, yystack_[0].location.begin.line); }
#line 1459 "parser.tab.cpp"
    break;

  case 68: // type: CHAR
#line 408 "parser.y"
           { yylhs.value.as < Node* > () = new TypeNode(Type{BaseType::Char}, yystack_[0].location.begin.line); }
#line 1465 "parser.tab.cpp"
    break;

  case 69: // type: VOID
#line 409 "parser.y"
           { yylhs.value.as < Node* > () = new TypeNode(Type{BaseType::Void}, yystack_[0].location.begin.line); }
#line 1471 "parser.tab.cpp"
    break;


#line 1475 "parser.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -54;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     376,   -54,   -54,   -54,   -54,   -10,    -8,    -5,    -1,   -15,
     -54,   -54,   146,   178,   178,    26,   376,   -54,   -54,   -54,
      13,   -54,   -54,   -54,   -54,   -54,    19,    25,    34,    37,
      22,   -11,    14,    17,   -54,   -54,    45,   146,   395,   146,
     -54,    30,   -54,   146,   146,    42,    54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   -12,    44,   -54,    51,
     -54,    61,    58,   -54,   -54,     1,   -54,   -54,    37,    22,
     -11,   -11,    14,    14,    14,    14,    17,    17,   -54,   -54,
      97,   146,    59,   401,    60,    62,   -54,   146,     3,   -54,
      70,   -54,   376,    49,    64,   376,   -54,    68,    97,   -54,
     120,    69,    75,   114,   152,   376,   -54,    96,   376,    85,
      91,    98,   -54,   184,    95,   216,   376,   376,   105,   -54,
     376,   -54,   248,   280,   376,   312,   -54,   -54,   344,   -54,
     -54
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    66,    67,    68,    69,     0,     0,     0,     0,    55,
      56,    57,     0,     0,     0,     0,     2,     3,     5,     6,
       0,     7,     8,     9,    10,    11,     0,     0,    35,    37,
      39,    41,    44,    49,    52,    59,     0,     0,    28,     0,
      32,     0,    34,    63,     0,     0,    55,    60,    61,     1,
       4,    18,    12,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,    29,     0,
      30,     0,     0,    33,    64,     0,    36,    58,    38,    40,
      42,    43,    47,    48,    45,    46,    50,    51,    53,    54,
      14,     0,     0,     0,    19,     0,    62,     0,     0,    15,
       0,    20,     0,     0,     0,     0,    65,     0,     0,    17,
       0,     0,     0,     0,     0,     0,    16,    22,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,    13,
       0,    27,     0,     0,     0,     0,    25,    26,     0,    23,
      24
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -54,   -54,   -53,   -16,   -54,   -54,    29,   -54,    83,   -54,
     -54,   -54,   -54,   -54,   -54,    -7,     2,   -54,    88,    90,
       0,    52,    -2,    -6,   -54,   -54,   -36
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,    15,    16,    17,    18,    98,    99,    19,    20,    21,
      22,    23,    69,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    75,    36
  };

  const unsigned char
  Parser::yytable_[] =
  {
      50,    41,    71,    58,    59,    45,    43,    47,    48,    90,
      42,    37,    44,    38,    42,    91,    39,     9,    10,    11,
      12,    60,    61,    96,    40,   107,    49,    97,    13,   108,
      67,    70,    72,    14,    56,    57,    74,    76,    51,    42,
      42,    42,    62,    63,    52,    42,    42,    64,    65,   110,
      53,    54,   114,    55,   100,    73,    80,    81,    88,    89,
      86,    87,   123,    66,    77,   125,    92,     9,    10,    11,
      12,   111,   100,   132,   133,    43,    93,   135,    13,    94,
      95,   138,   102,    14,   101,   105,   104,    91,   109,   113,
     106,   115,   118,    42,    50,    42,   112,   119,    50,    42,
       1,     2,     3,     4,   124,    42,   121,    50,   126,    50,
      82,    83,    84,    85,   127,    42,    50,    50,   130,    50,
     128,    68,    50,     1,     2,     3,     4,     5,   134,     6,
       7,     8,     9,    10,    11,    12,   120,   116,     9,    10,
      11,    12,    78,    13,   117,    79,     0,     0,    14,    13,
       0,     0,     0,     0,    14,     1,     2,     3,     4,     5,
       0,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       9,    10,    11,    12,     0,    13,   122,     0,     0,     0,
      14,    13,     0,     0,     0,     0,    14,     1,     2,     3,
       4,     5,     0,     6,     7,     8,    46,    10,    11,    12,
       0,     0,     9,    10,    11,    12,     0,    13,   129,     0,
       0,     0,    14,    13,     0,     0,     0,     0,    14,     1,
       2,     3,     4,     5,     0,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,    12,     0,     0,
     131,     0,     0,     0,     0,    13,     0,     0,     0,     0,
      14,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,    12,
       0,     0,   136,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    14,     1,     2,     3,     4,     5,     0,     6,
       7,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,     0,     0,   137,     0,     0,     0,     0,    13,
       0,     0,     0,     0,    14,     1,     2,     3,     4,     5,
       0,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,    12,     0,     0,   139,     0,     0,     0,
       0,    13,     0,     0,     0,     0,    14,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,    12,     0,     0,   140,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    14,     1,
       2,     3,     4,     5,     0,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,    12,     1,     2,
       3,     4,     0,     0,     0,    13,     0,     0,     0,     0,
      14,     0,     0,     9,    10,    11,    12,     0,     0,     9,
      10,    11,    12,     0,    13,     0,   103,     0,     0,    14,
      13,     0,     0,     0,     0,    14
  };

  const short
  Parser::yycheck_[] =
  {
      16,     8,    38,    14,    15,    12,    21,    13,    14,    21,
       8,    21,    27,    21,    12,    27,    21,    18,    19,    20,
      21,    32,    33,    22,    25,    22,     0,    26,    29,    26,
      37,    38,    39,    34,    12,    13,    43,    44,    25,    37,
      38,    39,    28,    29,    25,    43,    44,    30,    31,   102,
      25,    17,   105,    16,    90,    25,    56,    57,    64,    65,
      62,    63,   115,    18,    22,   118,    22,    18,    19,    20,
      21,    22,   108,   126,   127,    21,    25,   130,    29,    18,
      22,   134,    23,    34,    91,    23,    93,    27,    18,    25,
      97,    23,    23,    91,   110,    93,   103,    22,   114,    97,
       3,     4,     5,     6,     8,   103,   113,   123,    23,   125,
      58,    59,    60,    61,    23,   113,   132,   133,    23,   135,
      22,    38,   138,     3,     4,     5,     6,     7,    23,     9,
      10,    11,    18,    19,    20,    21,    22,   108,    18,    19,
      20,    21,    54,    29,    24,    55,    -1,    -1,    34,    29,
      -1,    -1,    -1,    -1,    34,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    18,    19,    20,    21,    -1,    -1,
      18,    19,    20,    21,    -1,    29,    24,    -1,    -1,    -1,
      34,    29,    -1,    -1,    -1,    -1,    34,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    18,    19,    20,    21,
      -1,    -1,    18,    19,    20,    21,    -1,    29,    24,    -1,
      -1,    -1,    34,    29,    -1,    -1,    -1,    -1,    34,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      34,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    34,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,     3,     4,
       5,     6,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    18,
      19,    20,    21,    -1,    29,    -1,    25,    -1,    -1,    34,
      29,    -1,    -1,    -1,    -1,    34
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     9,    10,    11,    18,
      19,    20,    21,    29,    34,    37,    38,    39,    40,    43,
      44,    45,    46,    47,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    62,    21,    21,    21,
      25,    51,    52,    21,    27,    51,    18,    59,    59,     0,
      39,    25,    25,    25,    17,    16,    12,    13,    14,    15,
      32,    33,    28,    29,    30,    31,    18,    51,    44,    48,
      51,    62,    51,    25,    51,    61,    51,    22,    54,    55,
      56,    56,    57,    57,    57,    57,    58,    58,    59,    59,
      21,    27,    22,    25,    18,    22,    22,    26,    41,    42,
      62,    51,    23,    25,    51,    23,    51,    22,    26,    18,
      38,    22,    51,    25,    38,    23,    42,    24,    23,    22,
      22,    51,    24,    38,     8,    38,    23,    23,    22,    24,
      23,    24,    38,    38,    23,    38,    24,    24,    38,    24,
      24
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      39,    39,    39,    40,    41,    41,    41,    42,    43,    44,
      44,    45,    46,    46,    47,    47,    47,    47,    48,    48,
      48,    49,    50,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    55,    55,    56,    56,    56,    56,    56,    57,
      57,    57,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    61,    61,    62,    62,    62,    62
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     8,     0,     1,     3,     2,     2,     2,
       4,     2,     7,    11,    11,    10,    10,     9,     0,     1,
       1,     7,     2,     3,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     1,     1,     3,     1,
       2,     2,     4,     0,     1,     3,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "VOID", "IF", "ELSE", "FOR", "WHILE", "RETURN", "EQ", "NE", "LE", "GE",
  "AND", "OR", "IDENTIFIER", "NUMBER", "CHAR_LITERAL", "'('", "')'", "'{'",
  "'}'", "';'", "','", "'='", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'",
  "'!'", "UMINUS", "$accept", "program", "statement_list", "statement",
  "function_def", "param_list", "param", "declaration",
  "declaration_no_semi", "assignment", "if_stmt", "for_stmt", "for_init",
  "while_stmt", "return_stmt", "expression", "assignment_expr",
  "logical_or_expr", "logical_and_expr", "equality_expr",
  "relational_expr", "arithmetic_expr", "term", "factor", "function_call",
  "arg_list", "type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    81,    81,    88,    93,   100,   101,   102,   103,   104,
     105,   106,   107,   115,   128,   129,   134,   141,   152,   156,
     164,   176,   179,   185,   195,   203,   210,   217,   228,   229,
     230,   234,   243,   244,   252,   253,   257,   264,   265,   274,
     275,   284,   285,   291,   300,   301,   307,   313,   319,   328,
     329,   335,   344,   345,   351,   360,   363,   367,   368,   369,
     370,   375,   383,   393,   394,   399,   406,   407,   408,   409
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,     2,     2,     2,
      21,    22,    30,    28,    26,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      32,    27,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    35
    };
    // Last valid token kind.
    const int code_max = 276;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 7 "parser.y"
} // SimpleCompiler
#line 2142 "parser.tab.cpp"

#line 412 "parser.y"


namespace SimpleCompiler {
void Parser::error(const Parser::location_type& l, const std::string& msg)
{
    std::cerr << "Syntax error at line " << l.begin.line << ": " << msg << std::endl;
}
}
