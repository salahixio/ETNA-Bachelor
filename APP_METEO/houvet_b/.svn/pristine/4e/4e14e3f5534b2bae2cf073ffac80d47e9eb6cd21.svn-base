angular.module('AppMeteo.services_graphs', [])

    .factory('Graphs', function() {
        var chartConfig = {
            options: {
                chart: {
                }
            },
            series: [],
            title: {
            },
            xAxis: {
            },
            loading: false,
            size: {}
        };

        return {
            setChartType: function (newType) {
                chartConfig.series = [];
                chartConfig.options.chart.type = newType;
                if(newType == "column") {
                    chartConfig.title.text = 'La rose des vents';
                    chartConfig.options.chart.polar =  true;
                }
                else if (newType == "line") {
                    chartConfig.title.text = 'Moyenne par heure';
                    chartConfig.options.chart.polar =  false;
                    chartConfig.xAxis.type = '';
                    chartConfig.xAxis.categories = ['00h','01h','02h','03h','04h','05h','06h','07h','08h','09h','10h','11h','12h','13h'
                        ,'14h','15h','16h','17h','18h','19h','20h','21h','22h','23h'];
                }
                else if (newType == "area") {
                    chartConfig.title.text = 'Full data Graph';
                    chartConfig.xAxis.type = 'datetime';
                    chartConfig.xAxis.categories = false;
                    chartConfig.options.chart.polar =  false;
                }
            },
            setChartSeries: function (columns, datas) {
                if (chartConfig.options.chart.type == "line") {
                    /*var averageDay = [];
                    var averageHours = [];
                    var minDay = [];
                    var minHours = [];
                    var maxDay = [];
                    var maxHours = [];
                    for(var hour=0; hour < 24; hour++) {
                        averageDay.push(columns[0].average);
                        minDay.push(columns[0].min);
                        maxDay.push(columns[0].max);
                        var sum = 0.0;
                        var count = 0.0;
                        var max = 0.0;
                        var min = datas[0][0];
                        var value = 0.0;
                        var i = (hour * 720) + 2;
                        console.log(datas);
                        console.log(i);
                        for (var j=0; j < 720; j++) {
                            value = parseFloat(datas[i][0]);
                            if (!isNaN(value)) {
                                sum += value;
                                count++;
                            }
                            if (!isNaN(value) && value < min) {
                                min = value;
                            }
                            if (!isNaN(value) && value > max) {
                                max = value;
                            }
                            i++;
                        }
                        if (!isNaN(parseFloat(sum/count)))
                            averageHours = sum/count;
                        else
                            averageHours = "";
                        minHours = min;
                        maxHours = max;
                    }
                    chartConfig.series.push({"name" : "moyenne de la journée", "data": averageDay});
                    chartConfig.series.push({"name" : "minimum de la journée", "data": minDay});
                    chartConfig.series.push({"name" : "maximum de la journée", "data": maxDay});
                    chartConfig.series.push({"name" : "moyenne par heure", "data": averageHours});
                    chartConfig.series.push({"name" : "minimum par heure", "data": minHours});
                    chartConfig.series.push({"name" : "maximum par heure", "data": maxHours});*/
                }
                else if (chartConfig.options.chart.type == "area") {
                    var tmp;
                    for(var i = 0; i < datas.length; i++) {
                        tmp = datas[i][0];
                        datas[i][0] = Date.parse(datas[i][1]) + (1000 * 60 * 60);
                        datas[i][1] = parseFloat(tmp);
                    }
                    chartConfig.series.push({"name" : "full data", "data": datas});
                }
            },
            getConfig: function () {
              return chartConfig;
            }
        };
    });