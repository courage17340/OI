var
  f1,f2:text;
  a:array[0..301,1..5] of integer;
  i,j,n:integer;
procedure init;
begin
  fillchar(a,sizeof(a),0);
  read(n);
  for i:=1 to n do a[i,1]:=i;
  for i:=1 to n do
    begin
      for j:=2 to 4 do
        begin
          read(a[i,j]);
          a[i,5]:=a[i,5]+a[i,j];
        end;
    end;
end;
procedure sort;
var
  p,q,t,k:integer;
begin
  for p:=1 to n do
    for q:=p+1 to n do
      if a[p,5]<a[q,5]
        then
          for k:=1 to 5 do
            begin
              t:=a[p,k];
              a[p,k]:=a[q,k];
              a[q,k]:=t;
            end
        else
          if a[p,5]=a[q,5]
            then
              if a[p,2]<a[q,2]
                then
                  for k:=1 to 5 do
                    begin
                      t:=a[p,k];
                      a[p,k]:=a[q,k];
                      a[q,k]:=t;
                    end
                else if a[p,1]>a[q,1]
                  then
                    for k:=1 to 5 do
                      begin
                        t:=a[p,k];
                        a[p,k]:=a[q,k];
                        a[q,k]:=t;
                      end;
end;
procedure work;
begin
  for i:=1 to 5 do
    begin
      writeln(a[i,1],' ',a[i,5]);
    end;
end;
begin{main}
  init;
  sort;
  work;
end.