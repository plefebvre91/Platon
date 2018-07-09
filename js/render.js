//! C'est sale, je sais
let app = new App();
app.run(2);

let p = app.getPoints();
let t = app.getTriangles();

let scene = new THREE.Scene();
let camera = new THREE.PerspectiveCamera( 40, window.innerWidth/window.innerHeight, 0.1, 100 );
let renderer = new THREE.WebGLRenderer();
renderer.setSize( window.innerWidth/4, window.innerHeight/3.4 );
document.getElementById("rend").appendChild( renderer.domElement );

let geometry = new THREE.Geometry();

let r = 1.0;
let c = Math.cos(60);

let i;

for(i=0; i<p.length; i++) {
    geometry.vertices.push(new THREE.Vector3(p[i].x, p[i].y, p[i].z));
}

for (i=0; i<t.length; i++) {
    geometry.faces.push( new THREE.Face3( t[i][0], t[i][1], t[i][2]));
}


let material = new THREE.MeshBasicMaterial( { color: 0xDADADA, wireframe: true } );
let cube = new THREE.Mesh( geometry, material );
scene.add( cube );

camera.position.z = 3;

let render = () => {
    requestAnimationFrame( render );
    cube.rotation.x += 0.01;
    cube.rotation.y += 0.01;
    renderer.render(scene, camera);
};

render();

