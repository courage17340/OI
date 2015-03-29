type
 arr=record
  cost,up:longint;
  end;
var
 a:array[0..1000] of arr;
 n,m,i,j,ans,p,q:longint;
begin
 readln(n,m);ans:=0;
 for i:=1 to n do readln(a[i].cost,a[i].up);
 for i:=1 to m do
  begin
   p:=1;q:=a[1].cost;
   for j:=1 to n do
    if a[j].cost<q then
     begin
      p:=j;
      q:=a[j].cost;
     end;
   ans:=ans+q;
   a[p].cost:=a[p].cost+a[p].up;
  end;
 writeln(ans);
end.