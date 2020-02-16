package excepciones;

public class JugadorExisteException extends Exception
{

	private static final long serialVersionUID = 1L;
	
	private String mensaje;
	
	public JugadorExisteException (String mensaje)
	{ 
		this.mensaje = mensaje; 
	}
	
	public String darMensaje()
	{ 
		return mensaje; 
	}
	
}
