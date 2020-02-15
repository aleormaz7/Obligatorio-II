package excepciones;

public class NoHayPartidaDisponibleException 
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
