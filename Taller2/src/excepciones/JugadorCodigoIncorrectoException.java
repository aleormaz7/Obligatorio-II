package excepciones;

public class JugadorCodigoIncorrectoException
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
