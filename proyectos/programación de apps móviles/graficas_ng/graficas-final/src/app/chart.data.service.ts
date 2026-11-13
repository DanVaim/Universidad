import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs';

interface ChartData {
  labels: string[];
  data: number[];
}

@Injectable({
  providedIn: 'root'
})
export class ChartDataService {
  private dataSubject = new BehaviorSubject<ChartData>({
    labels: ['Pad', 'Daniel', 'Mario', 'Wanfredo'],
    data: [20, 20, 20.5, 1]
  });
  data$ = this.dataSubject.asObservable();

  updateData(newData: ChartData) {
    this.dataSubject.next(newData);
  }
}
