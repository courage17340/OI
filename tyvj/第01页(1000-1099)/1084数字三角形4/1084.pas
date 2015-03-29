var
 a:array[0..25,0..25] of int64;
 i,j,n,x,y:longint;
 ans:int64;
function max(a,b:int64):int64;
begin max:=a;if a<b then max:=b;end;
begin
 readln(n);
 for i:=1 to n do
  begin
   for j:=1 to i do read(a[i,j]);
   readln;
  end;
 readln(x,y);
 a[x,y]:=a[x,y]+maxlongint;
 for i:=2 to n do
  for j:=1 to i do a[i,j]:=max(a[i-1,j],a[i-1,j-1])+a[i,j];
 ans:=0;
 for i:=1 to n do if a[n,i]>ans then ans:=a[n,i];
 writeln(ans-maxlongint);
end.