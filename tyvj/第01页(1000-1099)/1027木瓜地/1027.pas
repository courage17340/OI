var
  a:array[0..41,0..41] of longint;
  i,j,n,m,ans,x,y,num:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(n,m);
  for i:=1 to n do for j:=1 to m do read(a[i,j]);
  ans:=a[1,1];
  a[1,1]:=0;
  x:=1;
  y:=1;
  while (x<>n)or(y<>m) do
    begin
      num:=0;
      if num<a[x-1,y] then begin num:=a[x-1,y];i:=x-1;j:=y;end;
      if num<a[x+1,y] then begin num:=a[x+1,y];i:=x+1;j:=y;end;
      if num<a[x,y-1] then begin num:=a[x,y-1];i:=x;j:=y-1;end;
      if num<a[x,y+1] then begin num:=a[x,y+1];i:=x;j:=y+1;end;
      x:=i;y:=j;
      ans:=ans+a[x,y];
      a[x,y]:=0;
    end;
  writeln(ans);
end.