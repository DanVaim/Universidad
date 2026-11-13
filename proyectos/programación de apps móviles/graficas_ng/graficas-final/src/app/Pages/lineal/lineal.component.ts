import { Component, AfterViewInit, OnDestroy, ChangeDetectorRef } from '@angular/core';
import { Chart, ChartType, Colors } from 'chart.js/auto';
import { ChartDataService } from '../../chart.data.service';
import { Subscription } from 'rxjs';
import { DataComponent } from "../../data/data.component";
//Recuerda colocar el Observable específico
@Component({
    selector: 'app-lineal',
    standalone: true,
    templateUrl: './lineal.component.html',
    styleUrls: ['./lineal.component.css'],
    imports: [DataComponent]
})
export class LinealComponent implements AfterViewInit, OnDestroy {
addData() {
  
} //Creación de los charts o gráficos, clase Chart de ChartJS
  public chart: Chart | undefined; 
  private dataSubscription: Subscription | undefined; // Suscripción para recibir datos

  constructor(private chartDataService: ChartDataService, private cdr: ChangeDetectorRef) {}

  ngAfterViewInit() { // Se subscribe al observable del servicio para recibir datos
    this.dataSubscription = this.chartDataService.data$.subscribe(chartData => {
      if (this.chart) { // Si el gráfico ya está inicializado, se actualizan los datos
        this.chart.data.labels = chartData.labels;
        this.chart.data.datasets[0].data = chartData.data;
        this.chart.update();
      } else {
        // Si el gráfico no está inicializado, se crea con los datos recibidos
        this.initializeChart(chartData.labels, chartData.data);
      }
      // Se notifica que los datos han cambiado para actualizar la vista
      this.cdr.detectChanges(); 
    });
  }

  initializeChart(labels: string[], data: number[]) {
    const chartData = {
      labels: labels,
      datasets: [{
        label: 'Lineal',
        data: data,
        fill: true,
        stacked: true,
        borderColor: 'rgb(0, 0, 0)',
        borderCapStyle: ['rgb(312, 244, 12)', 'rgb(25, 9, 132)', 'rgb(34, 16, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(55, 99, 32)', 'rgb(54, 162, 235)', 'rgb(25, 25, 8)', 'rgb(175, 122, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)',]

      }]
    };

    this.chart = new Chart('chart', {
      type: 'line'as ChartType,
      data: chartData,
    });
  }

  ngOnDestroy() {
    if (this.dataSubscription) {
      this.dataSubscription.unsubscribe();
    }
  }
}
