var
  a:array[0..200,0..200] of longint;
  ch:char;
  i,j,m,n,ans,x,y:longint;
  t:boolean;
begin
  readln(m,n,y,x);
  for i:=0 to n+1 do begin a[i,0]:=maxlongint;a[i,m+1]:=maxlongint;end;
  for j:=0 to m+1 do begin a[0,j]:=maxlongint;a[n+1,j]:=maxlongint;end;
  for i:=n downto 1 do
    begin
      for j:=1 to m do
        begin
          read(ch);
          case ch of
            '.':a[i,j]:=-1;
            '*':a[i,j]:=maxlongint;
            end;
        end;
      readln;
    end;
  a[x,y]:=0;
  t:=true;i:=0;ans:=0;
  while t do
    begin
      t:=false;
      for x:=1 to n do
        for y:=1 to m do
          if a[x,y]=-1 then
          if (a[x,y-1]=i)or(a[x,y+1]=i)or(a[x-1,y]=i)or(a[x+1,y]=i)or(a[x-1,y-1]=i)or(a[x-1,y+1]=i)or(a[x+1,y-1]=i)or(a[x+1,y+1]=i) then
            begin
               t:=true;
               a[x,y]:=i+1;
            end;
       inc(i);inc(ans);
     end;
  writeln(i-1);
end.