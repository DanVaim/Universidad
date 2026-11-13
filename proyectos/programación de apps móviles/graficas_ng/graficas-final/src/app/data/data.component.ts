import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { ChartDataService } from '../chart.data.service';

@Component({
  selector: 'app-data',
  standalone: true,
  imports: [FormsModule],
  templateUrl: './data.component.html',
  styleUrls: ['./data.component.css']
})
export class DataComponent {    //Modificador de los valores de las gráficas
  newLabels: string = '';
  newData: string = '';

  constructor(private chartDataService: ChartDataService) {}

  updateData() {
    const labels = this.newLabels.split(',').map(label => label.trim());
    const data = this.newData.split(',').map(num => parseFloat(num.trim()));
    this.chartDataService.updateData({ labels, data });
  }
}
