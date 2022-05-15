Vue.use(VueNativeSock.default, 'ws://' + location.hostname + '/ws', { 
  format: 'json',
  reconnection: true, // (Boolean) whether to reconnect automatically (false)
  reconnectionAttempts: 5, // (Number) number of reconnection attempts before giving up (Infinity),
  reconnectionDelay: 5000, // (Number) how long to initially wait before attempt
})


//Botones Persianas
Vue.component('action', {
  props: ['action'],
  template: ` 
        <v-btn fab large color="#FF1744" @click="doAction">
        <v-icon>{{action.text}}</v-icon>
        </v-btn>         
`,
  methods: {
    doAction: function (evt) {
      console.log(this.action.text + ': ' + this.action.id);
      let data = {
        command: "buttonAction",
        id: this.action.id,
      }
      let json = JSON.stringify(data);
      this.$socket.send(json);
      this.action.callback();
    }
  }
})

//Configuraciones
Vue.component('gpio-output', {
  props: ['config'],
  template: ` 
    <v-list-tile avatar>
      <v-list-tile-content>
        <v-list-tile-title>{{config.text}}</v-list-tile-title>
      </v-list-tile-content>
      <v-list-tile-action>
        <v-switch v-model="config.status" class="ma-2" :label="config.status ? 'ON' : 'OFF'" @change="sendConfig"></v-switch>
      </v-list-tile-action>
    </v-list-tile>
`,
  methods: {
    sendConfig: function (evt) {
      console.log(this.config.id + ': ' + this.config.status);
      let data = {
        command: "switchConfig",
        id: this.config.id,
        status: this.config.status
      }
      let json = JSON.stringify(data);
      this.$socket.send(json);
    }
  }
})


//Información
Vue.component('gpio-input', {
  props: ['information'],
  template: `

    <v-list-tile avatar>
      <v-list-tile-content>
        <v-list-tile-title>{{information.text}}</v-list-tile-title>
      </v-list-tile-content>

      <v-list-tile-action>
        <v-chip color="blue" text-color="white">{{information.status}}</v-chip>
      </v-list-tile-action>
    </v-list-tile>
    
    `
})

//Prueba
Vue.component('change-hour',{
  props: ['hours'],
  template:`
    <v-list-tile avatar>
        <v-list-tile-content>
          <v-list-tile-title>{{hours.text}}</v-list-tile-title>
        </v-list-tile-content>

        <v-list-tile-action>
          <v-chip color="blue" text-color="white">{{hours.status}}</v-chip>
        </v-list-tile-action>
    </v-list-tile>
    `
})



var app = new Vue({
  el: '#app',
  data: function () {
    return {
      
      action_list1: [
        { id: 0, text: 'mdi-chevron-up-circle-outline', callback: () => console.log("Subir1") },
        { id: 2, text: 'mdi-circle-outline', callback: () => console.log("Stop1") },
        { id: 1, text: 'mdi-chevron-down-circle-outline', callback: () => console.log("Bajar1") },
      ],
      action_list2: [
        { id: 3, text: 'mdi-chevron-up-circle-outline', callback: () => console.log("Subir2") },
        { id: 5, text: 'mdi-circle-outline', callback: () => console.log("Stop2") },
        { id: 4, text: 'mdi-chevron-down-circle-outline', callback: () => console.log("Bajar2") },
      ],
      action_list3: [
        { id: 6, text: 'mdi-chevron-up-circle-outline', callback: () => console.log("SubirTodo") },
        { id: 8, text: 'mdi-circle-outline', callback: () => console.log("StopTodo") },
        { id: 7, text: 'mdi-chevron-down-circle-outline', callback: () => console.log("BajarTodo") },
      ],

      config_list: [
        { id: 9, text: 'Modo Automático Noche', status: 0 },
        { id: 10, text: 'Modo Automático Dia', status: 0 },
        { id: 11, text: 'Mitad persiana', status: 0 },
        { id: 12, text: 'Horario Verano', status: 0 },
      ],

      information_list: [
        { id: 13, text: 'SSID', status: '#NA'},
        { id: 14, text: 'RSSI', status: '#NA'},
        { id: 19, text: 'IP', status: '#NA'},
        { id: 20, text: 'Puerta Enlace', status: '#NA'},
        { id: 21, text: 'DNS', status: '#NA'},
        { id: 17, text: 'Hora Actual', status: '#NA'},
        { id: 18, text: 'Tiempo activo', status: '#NA'},
      ],

      hour_list: [
        { id: 15, text: 'Hora Modo Noche', status: '#NA'},
        { id: 16, text: 'Hora Modo Día', status: '#NA'},
      ],
      
      time: null,
      menu2: false,
      modal2: false,
    }
  },

  mounted() {
    this.$socket.onmessage = (dr) => {
      console.log(dr);
      let json = JSON.parse(dr.data); 
      let config = this.$data.config_list.find(config => config.id == json.id);
      let information = this.$data.information_list.find(information => information.id == json.id);
      let hour = this.$data.hour_list.find(hour => hour.id == json.id);

      if (typeof config !== 'undefined'){
        console.log("undefined config");
        config.status = json.status;
      }
      if (typeof information !== 'undefined'){
        console.log("undefined information");
        information.status = json.status;
      }
      if (typeof hour !== 'undefined'){
        console.log("undefined information");
        hour.status = json.status;
      }

    }
  }

})
