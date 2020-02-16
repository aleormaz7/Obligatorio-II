package excepciones;

public class NoHayPartidaDisponibleException  extends Exception
{
	private String mensaje;
	
	public NoHayPartidaDisponibleException (String mensaje)
	{ 
		this.mensaje = mensaje; 
	}
	
	public String darMensaje()
	{ 
		return mensaje; 
	}
	
	

}
