package excepciones;

public class JugadorCodigoIncorrectoException extends Exception
{
		
	private String mensaje;
	
	public JugadorCodigoIncorrectoException (String mensaje)
	{ 
		this.mensaje = mensaje; 
	}
	
	public String darMensaje()
	{ 
		return mensaje; 
	}
	

}
