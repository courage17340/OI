var
  a:array[0..100] of longint;
  path,f:array[0..100,0..100] of longint;
  n,i:longint;
function Dp(L,r:longint):longint;
var i,x:longint;
begin
  if f[L,r]=0 then
    begin
      if L>r
        then begin f[L,r]:=1;path[L,r]:=0;end
        else if L=r
          then begin f[L,r]:=a[L];path[L,r]:=L;end
          else
            begin
              for i:=L to r do
                begin
                  x:=Dp(L,i-1)*Dp(i+1,r)+a[i];
                  if x>f[L,r] then
                    begin
                      f[L,r]:=x;
                      path[L,r]:=i;
                    end;
                end;
            end;
    end;
  exit(f[L,r]);
end;
procedure print(L,r:longint);
begin
  if path[L,r]>0 then
    begin
      write(path[L,r]);
      if not((L=r)and(r=n)) then write(' ');
      print(L,path[L,r]-1);
      print(path[L,r]+1,r);
    end;
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  fillchar(f,sizeof(f),0);
  writeln(Dp(1,n));
  print(1,n);
end.