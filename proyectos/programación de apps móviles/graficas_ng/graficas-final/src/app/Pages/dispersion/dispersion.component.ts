import { Component, AfterViewInit, OnDestroy, ChangeDetectorRef } from '@angular/core';
import { Chart, ChartType } from 'chart.js/auto';
import { DataComponent } from "../../data/data.component";
import { ChartDataService } from '../../chart.data.service';
import { Subscription } from 'rxjs';

@Component({
    selector: 'app-dispersion',
    standalone: true,
    templateUrl: './dispersion.component.html',
    styleUrls: ['./dispersion.component.css'],
    imports: [DataComponent]
})
export class DispersionComponent implements AfterViewInit, OnDestroy {
  public chart: Chart | undefined;
  private dataSubscription: Subscription | undefined;

  constructor(private chartDataService: ChartDataService, private cdr: ChangeDetectorRef) {}

  ngAfterViewInit() {
    this.dataSubscription = this.chartDataService.data$.subscribe(chartData => {
      if (this.chart) {
        this.chart.data.labels = chartData.labels;
        this.chart.data.datasets[0].data = chartData.data;
        this.chart.update();
      } else {
        this.initializeChart(chartData.labels, chartData.data);
      }
      
      this.cdr.detectChanges(); 
    });
  }

  initializeChart(labels: string[], data: number[]) {
    const chartData = {
      labels: labels,
      datasets: [{
        label: 'Punto',
        data: data,
        fill: true,
        borderColor: ['rgb(104, 106, 255)', 'rgb(255, 73, 73)', 'rgb(255, 9, 132)', 'rgb(34, 16, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(55, 99, 32)', 'rgb(54, 162, 235)', 'rgb(25, 25, 8)', 'rgb(175, 122, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)', 'rgb(75, 192, 192)', 'rgb(255, 99, 132)', 'rgb(54, 162, 235)', 'rgb(255, 205, 86)',],

      }]
    };

    this.chart = new Chart('chart', {
      type: 'bubble' as ChartType,
      data: chartData,
    });

    // this.chart = new Chart('chart', {      No funciona adecuadamente Pad, el de bubble cumple la funcion
    //   type: 'scatter'as ChartType,
    //   data: chartData,
    // });
  }

  ngOnDestroy() {
    if (this.dataSubscription) {
      this.dataSubscription.unsubscribe();
    }
  }
}