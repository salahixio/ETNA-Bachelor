angular.module('AppMeteo.controllers', [])

    .controller('FilesCtrl', function($scope, File) {
      $scope.files = File.get();
    })
    .controller('UploadCtrl', function($scope) {

    })
    .controller('ListAnalysisCtrl', function($scope, $stateParams, $http, Parse) {
      $http.get('files/'+$stateParams.fileName+'.his').success(function(data) {
        var columns = Parse.columns(data);

        $scope.file = {name:$stateParams.fileName};
        $scope.cols = columns;
      }).
      error(function() {
        $scope.cols = [{name:"Error with file"}];
      });

    })
    .controller('RemoveCtrl', function($scope) {

    })
    .controller('DatasCtrl', function($scope, $stateParams, $http, Parse, Calcul) {
      $http.get('files/' + $stateParams.fileName + '.his').success(function (data) {
        var columns = Parse.column(data, $stateParams.analyse);
        var datas = Parse.lines(data, columns);
        columns = Calcul.average(datas, columns);
        columns = Calcul.min(datas, columns);
        columns = Calcul.max(datas, columns);
        $scope.datas = columns[0];
        $scope.file = {name:$stateParams.fileName};

      }).error(function () {
        $scope.file = {name: "", data: "Error with file"};
      })
    })
    .controller('GraphsCtrl', function($scope, $stateParams, $http, Parse, Calcul, Graphs) {
      $http.get('files/' + $stateParams.fileName + '.his').success(function (data) {
        var columns = Parse.column(data, $stateParams.dataType);
        var datas = Parse.lines(data, columns);
        columns = Calcul.average(datas, columns);
        columns = Calcul.min(datas, columns);
        columns = Calcul.max(datas, columns);

        Graphs.setChartType($stateParams.graphType);
        Graphs.setChartSeries(columns, datas);
        $scope.chartConfig = Graphs.getConfig();

      }).error(function () {
      })
    });
