void
err_prn /* [fnc] Print formatted error messages */
(char *err_msg) /* I [sng] Formatted error message to print */
{
  /* Purpose: Print error message (currently only to stdout) approximately in GNU style, i.e., "program_name: ERROR error message....\n". 
     Routine is intended to make error messages convenient to use in routines without routine itself needing access to copy of program. 
     Therefore a copy of this routine should be placed in each main.c file, just like the program's usg_prn() routine. */

  /* Routine is more difficult to implement practically than it first seemed, because 
     it assumes all calling routines have their error messages in a single string, when
     in reality, they often utilize var_args capabilities of fprintf() themselves and
     have multiple formatted inputs. Hold off for now. */

  (void)fprintf(stdout,"%s: %s",prg_nm_get(),err_msg);

} /* end err_prn() */
