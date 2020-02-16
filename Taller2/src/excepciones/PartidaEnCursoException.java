package excepciones;

public class PartidaEnCursoException extends Exception
{
	private String mensaje;
	
	public PartidaEnCursoException (String mensaje)
	{ 
		this.mensaje = mensaje; 
	}
	
	public String darMensaje()
	{ 
		return mensaje; 
	}
	
}
