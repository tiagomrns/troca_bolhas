// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"
#include "argv.h"
#include "ccfunc.h"

/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[]) {

  argterminal();

  inicio(z);

  while (!z.fim) {
    while (!z.novojogo) {
      while(z.inplay) {

      }
    }
  }


  return 0;
}


printf("./CandyCrush(1)                        Manual pager utils                        MAN(1)

NAME
       man - an interface to the on-line reference manuals

SYNOPSIS
       man  [-C  file]  [-d]  [-D]  [--warnings[=warnings]]  [-R encoding] [-L
       locale] [-m system[,...]] [-M path] [-S list]  [-e  extension]  [-i|-I]
       [--regex|--wildcard]   [--names-only]  [-a]  [-u]  [--no-subpages]  [-P
       pager] [-r prompt] [-7] [-E encoding] [--no-hyphenation] [--no-justifi‐
       cation]  [-p  string]  [-t]  [-T[device]]  [-H[browser]] [-X[dpi]] [-Z]
       [[section] page ...] ...
       man -k [apropos options] regexp ...
       man -K [-w|-W] [-S list] [-i|-I] [--regex] [section] term ...
       man -f [whatis options] page ...
       man -l [-C file] [-d] [-D] [--warnings[=warnings]]  [-R  encoding]  [-L
       locale]  [-P  pager]  [-r  prompt]  [-7] [-E encoding] [-p string] [-t]
       [-T[device]] [-H[browser]] [-X[dpi]] [-Z] file ...
       man -w|-W [-C file] [-d] [-D] page ...
       man -c [-C file] [-d] [-D] page ...
       man [-?V]

DESCRIPTION
       man is the system's manual pager.  Each page argument given to  man  is
       normally  the  name of a program, utility or function.  The manual page
       associated with each of these arguments is then found and displayed.  A
       section,  if  provided, will direct man to look only in that section of
       the manual.  The default action is to search in all  of  the  available
       sections following a pre-defined order ("1 n l 8 3 2 3posix 3pm 3perl 5
       4 9 6 7" by default, unless overridden  by  the  SECTION  directive  in
       /etc/manpath.config),  and  to  show only the first page found, even if
       page exists in several sections.
\n", );
