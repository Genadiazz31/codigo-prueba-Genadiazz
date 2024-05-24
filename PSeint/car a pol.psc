Algoritmo programa
	Escribir "Bienvenido al programa para cambiar entre forma polar y cartesiana"
	Escribir "Si quieres cambiar de polar a cartesiana ingresa 1"
	Escribir "Si quieres cambiar de cartesiana a polar ingresa 2"
	Leer forma
	Segun forma Hacer
		1:
			Escribir "Ingresa el angulo"
			Leer angulo
			Escribir "Ingresa el modulo"
			Leer modulo
			anguloradianes = angulo*(pi/180)
			coordenadax = modulo* COS(anguloradianes)
			coordenaday = modulo* SEN(anguloradianes)
			Escribir "La coordenada en X es", coordenadax
			Escribir "La coordenada en Y es", coordenaday
		2:
			Escribir "Ingresa coordenada en X"
			Leer coordenadax
			Escribir "Ingresa coordenada en Y"
			Leer coordenaday
			modulo = RC(coordenadax*coordenadax + coordenaday*coordenaday)
			anguloradianes = ATAN(coordenaday/coordenadax)
			angulo = anguloradianes * (180/pi)
			Escribir "El modulo es", modulo
			Escribir "El angulo es" , angulo
	FinSegun
FinAlgoritmo
