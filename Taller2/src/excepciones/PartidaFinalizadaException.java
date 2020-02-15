package excepciones;

public class PartidaFinalizadaException 
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
