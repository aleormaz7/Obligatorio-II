package excepciones;

public class PartidaFinalizadaException extends Exception
{
	private String mensaje;
	
	public PartidaFinalizadaException (String mensaje)
	{ 
		this.mensaje = mensaje; 
	}
	
	public String darMensaje()
	{ 
		return mensaje; 
	}

}
