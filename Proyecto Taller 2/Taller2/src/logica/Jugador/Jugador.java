package logica.Jugador;

public class Jugador 
{
	private String nombre;
	
	private int codigoIngreso;
	
	private int puntajeTotal;
	
	private int cantidadPartidasFinalizadas;
	
	private int coeficiente;

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

	public int getCoeficiente() {
		return coeficiente;
	}

	public void setCoeficiente(int coeficiente) {
		this.coeficiente = coeficiente;
	}

	public int getCodigoIngreso() {
		return codigoIngreso;
	}
	
	//TODO:SECUENCIA PARTIDAS

}
