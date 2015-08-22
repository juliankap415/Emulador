/**
* \brief Función realiza suma entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación suma
*/
int ADD( long int Registro1,long int Registro2);

/**
* \brief Función realiza operación lógica AND entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación AND
*/
int AND(long int Registro1,long int Registro2);

/**
* \brief Función realiza operación lógica X-OR entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación X-OR
*/
int EOR(long int Registro1,long int Registro2);

/**
* \brief Realiza una copia del registro 2 a registro 1
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Copia de registro
*/
int MOV(long int Rdm,long int Rm);

/**
* \brief Función realiza operación lógica OR entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación OR
*/
int ORR(long int Registro1,long int Registro2);

/**
* \brief Función realiza resta entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación resta
*/
int SUB(long int Registro1,long int Registro2);
