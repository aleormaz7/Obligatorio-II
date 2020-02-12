package logica.Jugador;

public class Jugador 
{
	private String nombre;
	
	private String codigoIngreso;
	
	private int puntajeTotal;
	
	private int cantidadPartidasFinalizadas;
	
	private int cociente;
	
	//TODO:SECUENCIA PARTIDAS
	
	public Jugador(String nombre, String codigoIngreso)
	{
		this.nombre = nombre;
		this.codigoIngreso = codigoIngreso;
		this.puntajeTotal = 0;
		this.cantidadPartidasFinalizadas = 0;
		this.cociente = 0;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public int getPuntajeTotal() {
		return puntajeTotal;
	}

	public void setPuntajeTotal(int puntajeTotal) {
		this.puntajeTotal = puntajeTotal;
	}

	public int getCantidadPartidasFinalizadas() {
		return cantidadPartidasFinalizadas;
	}

	public void setCantidadPartidasFinalizadas(int cantidadPartidasFinalizadas) {
		this.cantidadPartidasFinalizadas = cantidadPartidasFinalizadas;
	}

	public int getCociente() {
		return cociente;
	}

	public void setCociente(int coeficiente) {
		this.cociente = coeficiente;
	}

	public String getCodigoIngreso() {
		return codigoIngreso;
	}
	
	
}
