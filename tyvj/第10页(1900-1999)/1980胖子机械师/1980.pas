type
  rec=record
        x,y,z:longint;  
      end;  
var
  a:array[0..51,0..51,0..51] of longint;  
  yes:array[0..51,0..51,0..51] of boolean;  
  b:array[1..130000] of rec;  
  n,i,j,k,L,W,H,ans,p,kkk:longint;  
function pan(a,b:longint):boolean;  
begin
  if abs(a-b)<=kkk then exit(true);  
  exit(false);  
end;  
procedure work(x1,y1,z1:longint);  
var
  i,j,k,p,q:longint;  
begin
  b[1].x:=x1;  
  b[1].y:=y1;  
  b[1].z:=z1;  
  p:=1;q:=1;  
  while p<=q do
    begin
      if pan(a[b[p].x,b[p].y,b[p].z],a[b[p].x+1,b[p].y,b[p].z])  
        and yes[b[p].x+1,b[p].y,b[p].z] then
        begin inc(q);b[q].x:=b[p].x+1;b[q].y:=b[p].y;b[q].z:=b[p].z;  
        yes[b[p].x+1,b[p].y,b[p].z]:=false;end;  
    
      if pan(a[b[p].x,b[p].y,b[p].z],a[b[p].x-1,b[p].y,b[p].z])  
        and yes[b[p].x-1,b[p].y,b[p].z] then
        begin inc(q);b[q].x:=b[p].x-1;b[q].y:=b[p].y;b[q].z:=b[p].z;  
        yes[b[p].x-1,b[p].y,b[p].z]:=false;end;  
    
      if pan(a[b[p].x,b[p].y,b[p].z],a[b[p].x,b[p].y+1,b[p].z])  
        and yes[b[p].x,b[p].y+1,b[p].z] then
        begin inc(q);b[q].x:=b[p].x;b[q].y:=b[p].y+1;b[q].z:=b[p].z;  
        yes[b[p].x,b[p].y+1,b[p].z]:=false;end;  
    
      if pan(a[b[p].x,b[p].y,b[p].z],a[b[p].x,b[p].y-1,b[p].z])  
        and yes[b[p].x,b[p].y-1,b[p].z] then
        begin inc(q);b[q].x:=b[p].x;b[q].y:=b[p].y-1;b[q].z:=b[p].z;  
        yes[b[p].x,b[p].y-1,b[p].z]:=false;end;  
    
      if pan(a[b[p].x,b[p].y,b[p].z],a[b[p].x,b[p].y,b[p].z+1])  
        and yes[b[p].x,b[p].y,b[p].z+1] then
        begin inc(q);b[q].x:=b[p].x;b[q].y:=b[p].y;b[q].z:=b[p].z+1;  
        yes[b[p].x,b[p].y,b[p].z+1]:=false;end;  
    
      if pan(a[b[p].x,b[p].y,b[p].z],a[b[p].x,b[p].y,b[p].z-1])  
        and yes[b[p].x,b[p].y,b[p].z-1] then
        begin inc(q);b[q].x:=b[p].x;b[q].y:=b[p].y;b[q].z:=b[p].z-1;  
        yes[b[p].x,b[p].y,b[p].z-1]:=false;end;  
     inc(p);  
   end;  
end;  
begin
  fillchar(yes,sizeof(yes),true);  
  readln(L,w,h);  
  for i:=0 to 51 do
    for j:=0 to 51 do
      for k:=0 to 51 do
        a[i,j,k]:=-1000;  
  readln(kkk);  
  for i:=1 to L do
    for j:=1 to W do
      for k:=1 to H do
        read(a[i,j,k]);  
  ans:=0;  
  for i:=1 to L do
    for j:=1 to W do
      for k:=1 to H do
        if yes[i,j,k] and(a[i,j,k]<>-1000) then
          begin
            inc(ans);  
         {   fillchar(b,sizeof(b),0); } 
            work(i,j,k);  
          end;  
  writeln(ans);  
  readln;readln;  
end.