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
            yAxis: {
                plotLines:[]
            },
            loading: false,
            size: {}
        };

        return {
            setChartType: function (newType) {
                chartConfig.series = [];
                chartConfig.yAxis.plotLines = [];
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
                    var averageDay;
                    var averageHours = [];
                    var minDay;
                    var minHours = [];
                    var maxDay;
                    var maxHours = [];

                    averageDay = columns[0].average;
                    minDay = columns[0].min;
                    maxDay = columns[0].max;

                    for(var i = 2; i < datas.length - 1; i = i + 720) {
                        minHours.push(this.getMin(datas, i));
                        maxHours.push(this.getMax(datas, i));
                        averageHours.push(this.getAvg(datas, i));
                    }
                    chartConfig.yAxis.plotLines.push({"label": {text: 'moyenne de la journée'},"color" : "blue", "value": averageDay, "width": 2});
                    chartConfig.yAxis.plotLines.push({"label": {text: 'minimum de la journée'},"color" : "black", "value": minDay, "width": 2});
                    chartConfig.yAxis.plotLines.push({"label": {text: 'maximum de la journée'},"color" : "green", "value": maxDay, "width": 2});
                    chartConfig.series.push({"name" : "moyenne par heure", "data": averageHours});
                    chartConfig.series.push({"name" : "minimum par heure", "data": minHours});
                    chartConfig.series.push({"name" : "maximum par heure", "data": maxHours});
                }
                else if (chartConfig.options.chart.type == "area") {
                    var tmp;
                    for(var i = 0; i < datas.length; i++) {
                        tmp = datas[i][0];
                        var year = parseInt(datas[i][1].substr(0, 4));
                        var month = parseInt(datas[i][1].substr(5, 2));
                        var day = parseInt(datas[i][1].substr(8, 2));
                        var hour = parseInt(datas[i][1].substr(11, 2));
                        var min = parseInt(datas[i][1].substr(14, 2));
                        var sec = parseInt(datas[i][1].substr(17, 2));
                        datas[i][0] = Date.UTC(year, month, day, hour, min, sec);
                        datas[i][1] = parseFloat(tmp);
                    }
                    chartConfig.series.push({"name" : columns[0].name, "data": datas});
                }
            },
            getConfig: function () {
              return chartConfig;
            },
            getMin: function getMin(datas, pos) {
                var value = 0.0;
                if((pos + 720) > datas.length) {
                    var len = datas.length;
                } else {
                    var len = pos + 720;
                }
                var tmp = pos + 1;
                var min = parseFloat(datas[tmp][0]);
                while (isNaN(min)) {
                    tmp++;
                    min = parseFloat(datas[tmp][0]);
                }
                for(var i = pos + 1; i < len; i++) {
                    value = parseFloat(datas[i][0]);
                    if (!isNaN(value) && value < min) {
                        min = value;
                    }
                }
                return min;
            },
            getAvg : function getAvg(datas, pos) {
                var sum = 0.0;
                var count = 0.0;
                var average = 0.0;

                if((pos + 720) > datas.length) {
                    var len = datas.length;
                } else {
                    var len = pos + 720;
                }
                for(var i = pos + 1; i < len; i++) {
                    if (!isNaN(parseFloat(datas[i][0]))) {
                        sum += parseFloat(datas[i][0]);
                        count++;
                    }
                }
                if (!isNaN(parseFloat(sum/count)))
                    average = sum/count;
                else
                    average = 0.0;
                return average;
            },
            getMax : function getMax(datas, pos) {
                var max = 0.0;
                var value = 0.0;

                if((pos + 720) > datas.length) {
                    var len = datas.length;
                } else {
                    var len = pos + 720;
                }
                for(var i = pos + 1; i < len; i++) {
                    value = parseFloat(datas[i][0]);
                    if (!isNaN(value) && value > max) {
                        max = value;
                    }
                }
                return max;
            }
        };
    });